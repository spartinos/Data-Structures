  #include <iostream>
  #include "fstream"
  #include <string>
  #include <time.h>



  #include "ataksinomhtos.h"
  #include "taksinomhmenos.h"
  #include "Hashing.h"
  #include "BSTree.h"
  #include "AVLtree.h"

  using namespace std;



  void ftiakse_thn_leksi(string& insertwd, string wd)
  {
      for (int i = 0, length = wd.size(); i < length; i++)
      {
          // Μετατρέπει τα κεφαλαία σε πεζά
          if(isupper(wd[i]))
              wd[i] = wd[i] + 32;
  
          // Ο χαρακτήρας στην θέση i είναι πεζός , οπότε ελέγχω αν είναι μεταξύ a-z.
          //  Αν ναι τον εισάγω στη συμβολοσείρα.
          if ((wd[i] >= 'a' && wd[i] <= 'z')||wd[i]==' ')
              insertwd = insertwd + wd[i];
      }
  }




  template<typename Dtype>
  
  void Eisagwgh(Dtype& data, string fakelos_name, string name)
  {
      ofstream TimeOutput;
      string wd1,wd2; 
      clock_t arxh, telos;
      ifstream fakelos(fakelos_name, ios::in);


    
      if (!fakelos.is_open())
      {
          cout << "Fakelos not found!" << endl;
          exit (1) ;
      }


    
      // START : Timing for insert!
      arxh = clock();

    
      while (fakelos >> wd1 >> wd2)
      {
        // Συμβολοσειρά στην οποία θα εισάγω λέξεις.(Χωρίς σημεία στίξης-αριθμούς-κεφαλαία)
          string insertwd = "";
          if(fakelos.eof())
              break;
        
          ftiakse_thn_leksi(insertwd,wd1+" "+wd2);
        
          if(insertwd != "" )
              data.Insert(insertwd);
      }
  
      fakelos.close();
  
      telos = clock();
    
      // END: Timing for insert!
  
      // START: Record time in a file!
    
      double reqclocks = telos - arxh;
      TimeOutput.open("TimeOutput.txt", ios::app);
      TimeOutput << " (*) " << name << " ----> Creating: " << (float)reqclocks / CLOCKS_PER_SEC << " seconds" << endl;
      TimeOutput.close();
    
      // END: Record time in a file!
  }
  
  
  
  
  int main()
  {
      string fakelosname = "Gutenberg.txt";
      //string tree_fakelos_name = "tree_print.txt";//'Oρισμα στις inorder,preorder,posserder των δεντρων
      srand(time(0));
      double reqclocks;

    
      clock_t arxh, telos;

    
      ataksinomhtos unorderedArr;
      taksinomhmenos orderedArr;
      Hashing Hshmp;
      BSTree myBstree;
      AVLtree myAvltree;
  

    
      //"Output.txt": Αποθήκευση λέξεων και το πλήθος εμφανίσεων αυτών.

    
      ofstream Output("Output.txt");

    
      //"TimeOutput.txt" : Αποθήκευση χρόνου εισαγωγής και αναζήτησης για κάθε δομή.

    
      ofstream TimeOutput("TimeOutput.txt"); TimeOutput.close();
  

    
      // START: ATAKSINOMHTOS
  
      cout << " ~ Reading and inserting: ataksinomhtos" << endl;
      Eisagwgh(unorderedArr, fakelosname, "ataksinomhtos");
  
      long long int apo = rand() % (unorderedArr.getFFC()); //Τυχαία τιμή (Η αρχή του συνόλου που θα γίνουν οι αναζητήσεις). 
      long long int se =  apo + (rand() % (unorderedArr.getFFC() - apo + 1));  //Τυχαία τιμή (μεγαλύτερη της apo) η οποία δηλώνει το τέλος του συνόλου Q.


    
      // START: Create set Q.
  
      long long int pos = apo;
      long long int Qsetsize = se - apo; // Μέγεθος συνόλου Q(Στοιχεία του ataksinomhtos)

    
      string Qset[Qsetsize];

    
      for (long long unsigned int i = 0; i < Qsetsize; i++)
      {
          Qset[i] = unorderedArr[pos];
          pos++;
      }


    
      // END: Create set Q.
  
  
      cout << " ~ Searching: ataksinomhtos" << endl;
      Output << "From = " << apo << ", To = " << se << endl;

    
      // START: Search timing!
      arxh = clock();

    
      for (long long unsigned int i = 0; i < Qsetsize; i++)
      {
          long long unsigned int temporary, mesTi;
          string element = Qset[i];
          unorderedArr.Find(element, temporary, mesTi);
  
          Output << "ataksinomhtos: Word '" << element << "' exists [" << mesTi << "] times." << endl;
      }

    
      telos = clock();
    
      // END: Search timing!

    
      // START: Record time in a file
    
      reqclocks = telos - arxh;
      TimeOutput.open("TimeOutput.txt", ios::app);
      TimeOutput << " (*) ataksinomhtos ----> Searching: " << (float)reqclocks / CLOCKS_PER_SEC << " seconds\n" << endl;
      TimeOutput.close();

    
      // END: Record time in a file!

    
      cout << " ~ Done: ataksinomhtos\n" << endl;
      Output << endl;

    
      // END: ATAKSINOMHTOS
  

    
      // START: TAKSINOMHMENOS

    
      cout << " ~ Reading and inserting: taksinomhmenos" << endl;
      Eisagwgh(orderedArr, fakelosname, "taksinomhmenos");

    
      cout << " ~ Searching: taksinomhmenos" << endl;
      Output << "From = " << apo << ", To = " << se << endl;

    
      // START: Search timing!
    
      arxh = clock();

    
      for (long long unsigned int i = 0; i < Qsetsize; i++)
      {
          long long mesTi;
          string element = Qset[i];
          orderedArr.Find(element, mesTi);
          Output << "taksinomhmenos: Word '" << element << "' exists [" << mesTi << "] times." << endl;
      }

    
      telos = clock();
    
      // END: Search timing!

    
      // START: Record time in a file!

    
      reqclocks = telos - arxh;
      TimeOutput.open("TimeOutput.txt", ios::app);
      TimeOutput << " (*) taksinomhmenos ----> Searching: " << (float)reqclocks / CLOCKS_PER_SEC << " seconds\n" << endl;
      TimeOutput.close();

    
      // END: Record time in a file!

    
      cout << " ~ Done: taksinomhmenos \n" << endl;
      Output << endl;

    
      // END: TAKSINOMHMENOS
  

    
      // START: BSTree

    
      cout << " ~ Reading and inserting: BSTree" << endl;
      Eisagwgh(myBstree, fakelosname, "BSTree");

    
      cout << " ~ Searching: BSTree" << endl;
      Output << "From = " << apo << ", To = " << se << endl;

    
      // START: Search timing!

    
      arxh = clock();

    
      for (long long unsigned int i = 0; i < Qsetsize; i++)
      {
          long long mesTi;
          string element = Qset[i];
          myBstree.search(element, mesTi);
          Output << "BSTree: Word '" << element << "' exists [" << mesTi << "] times." << endl;
      }

    
      telos = clock();

    
      // END: Search timing!

    
      // START: Record time in a file!

    
      reqclocks = telos - arxh;
      TimeOutput.open("TimeOutput.txt", ios::app);
      TimeOutput << " (*) BSTree ----> Searching: " << (float)reqclocks / CLOCKS_PER_SEC << " seconds\n" << endl;
      TimeOutput.close();

    
      // END: Record time in a file!
    
  
      cout << " ~ Done: BSTree \n" << endl;
      Output << endl;

    
      // END: BSTree
  
  
      // START: AVLtree
    
  
      cout << " ~ Reading and inserting: AVLtree" << endl;
      Eisagwgh(myAvltree, fakelosname, "AVLtree");
  
      cout << " ~ Searching: AVLtree" << endl;
      Output << "From = " << apo << ", To = " << se << endl;

    
      // START: Search timing!

    
      arxh = clock();

    
      for (long long unsigned int i = 0; i < Qsetsize; i++)
      {
          long long mesTi;
          string element = Qset[i];
          myAvltree.search(element, mesTi);
          Output << "AVLtree: Word '" << element << "' exists [" << mesTi << "] times." << endl;
      }
  
      telos = clock();

    
      // END: Search timing!

    
      // START: Record time in a file!

    
      reqclocks = telos - arxh;
      TimeOutput.open("TimeOutput.txt", ios::app);
      TimeOutput << " (*) AVLtree ----> Searching: " << (float)reqclocks / CLOCKS_PER_SEC << " seconds\n" << endl;
      TimeOutput.close();

    
      // END: Record time in a file!

  
      cout << " ~ Done: AVLtree \n" << endl;
      Output << endl;

    
      // END: AVLtree
  
  
      // START: HASH TABLE

    
      cout << " ~ Reading and inserting: hash table" << endl;
      Eisagwgh(Hshmp, fakelosname, "hash table");

    
      cout << " ~ Searching: hash table" << endl;
      Output << "From = " << apo << ", To = " << se << endl;

    
      // START: Search timing!

    
      arxh = clock();

    
      for (long long unsigned int i = 0; i < Qsetsize; i++)
      {
          long long mesTi;
          string element = Qset[i];
          Hshmp.Find(element, reinterpret_cast<unsigned int &>(mesTi));
          Output << "Hash Table: Word '" << element << "' exists [" << mesTi << "] times." << endl;
      }

    
      telos = clock();

    
      // END: Search timing!

    
      // START: Record time in a file!

    
      reqclocks = telos - arxh;
      TimeOutput.open("TimeOutput.txt", ios::app);
      TimeOutput << " (*) Hash ----> Searching: " << (float)reqclocks / CLOCKS_PER_SEC << " seconds\n" << endl;
      TimeOutput.close();

    
      // END: Record time in a file!

  
      cout << " ~ Done: hash table \n" << endl;
      Output << endl;

    
      // END: HASH TABLE

    
      return 0;
  }