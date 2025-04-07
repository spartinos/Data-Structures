#include "BSTree.h"

using namespace std;

BSTree::BSTree() 
{
    
      riza = nullptr;
    
}

BSTree::~BSTree()
{
    
      destroy(riza);
  
}

void BSTree::destroy(node* riza)
{
  
      if (riza != nullptr)
      {
          destroy(riza->aristera);
          destroy(riza->deksia);
          delete(riza);
      }
  
}

bool BSTree::Insert(string wd)  // Εισαγωγή νέου κόμβου
{
    
    if (riza == nullptr) 
      {
          riza = new node(wd);
          return true;
      }
      return insert(riza, wd);
  
}


bool BSTree::insert(node* riza , const string &wd)
{
   
    if (wd == riza->data.val)  // Αν η wd υπάρχει ήδη στο BSTree, τότε αυξάνονται οι φορές εμφάνισης (mesTi) κατά ένα.
      {
            riza->data.mesTi++;
            return true;
      }
  
    
      if (wd > riza->data.val) 
        {
            if (riza->deksia == nullptr)
            {
                riza->deksia = new node(wd);  // H λέξη εισάγεται ως το δεξί παιδί της ρίζας.
                riza->deksia->gonios = riza;  // O γονιός του κόμβου που περιέχει τη νέα λέξη είναι η ρίζα.
    
                return true;
            }
            return insert (riza->deksia,wd);
      }
      else 
      {
            if (riza->aristera==nullptr)
            {
                riza->aristera = new node(wd);  //Η λέξη εισάγεται ως το αριστερό παιδί της ρίζας.
                riza->aristera->gonios = riza;  //Ο γονιός του κόμβου που περιέχει τη νέα λέξη είναι η ρίζα.
    
                return true;
            }
  
            // Αν η ρίζα έχει ήδη αριστερό παιδί επαναλαμβάνεται αναδρομικά η διαδικασία της εισαγωγής
            // λαμβάνοντας αυτή τη φορά ως ρίζα το αριστερό παιδί της ρίζας.
    
            return insert (riza->aristera, wd);
      }
}


void BSTree::Inorderprint(string file_name) 
{
      ofstream file;
    
      file.open(file_name, ios::app);
    
      file << "BSTree In order print" << endl << endl;
    
      inOrder (riza,file_name); 
      file << endl ;

}


void BSTree::inOrder (node* l, string file_name)
{
      if (l == nullptr) 
          return;

  
      inOrder (l->aristera,file_name);  // Αναδρομική κλήση για το αριστερό υποδέντρο
  
  
      // Θα γραφτούν μέσα στο αρχείο οι κόμβοι σε inorder.
  
      ofstream file;
  
      file.open(file_name, ios::app);
      file <<"string: "<< l->data.val << ", mesTi_existed: " << l->data.mesTi<<"!"<<endl;
      inOrder (l->deksia,file_name);
}

void BSTree::Preorderprint(string file_name)   
{
  
    ofstream file;
    file.open(file_name, ios::app);
  
    file << "BSTree Pre order print" << endl << endl;
    preOrder (riza,file_name);  
  
    file << endl ;
}


void BSTree::preOrder (node* l, string file_name)
{
  
      if (l == nullptr) 
          return;
  
      // Θα γραφτούν μέσα στο αρχείο οι κόμβοι σε preorder.
  
      ofstream file;
    
      file.open(file_name, ios::app);
      file <<"string: "<< l->data.val << ", mesTi_existed: " << l->data.mesTi<<"!"<<endl;
  
      preOrder (l->aristera,file_name);  
      preOrder (l->deksia,file_name);  

}

void BSTree::Postorderprint(string file_name)
{
      ofstream file;
    
      file.open(file_name, ios::app);
    
      file << "BSTree Post order print" << endl << endl;
      postOrder (riza,file_name);  
    
      file << endl;
}


void BSTree::postOrder (node* l, string file_name)
{
      if (l == nullptr) 
          return;
  
      postOrder (l->aristera,file_name); 
      postOrder (l->deksia,file_name); 
  
      // Θα γραφτούν μέσα στο αρχείο οι κόμβοι σε postorder.
  
      ofstream file;
      file.open(file_name, ios::app);
      file <<"string: "<< l->data.val << ", mesTi_existed: " << l->data.mesTi<<"!"<<endl;
}

bool BSTree::search(string wd, long long int& mesTi_existed)
{
      node* l = search(wd); 
  
      if(l == nullptr)  // Αν δε βρέθηκε η λέξη
      {
          mesTi_existed = 0;  
          return false; 
      }
  
      // Αν η λέξη βρεθεί.
      mesTi_existed = l->data.mesTi;
      return true;
}


node* BSTree::search(string wd)
{
      node* l; 
      l = riza;  // Ο κόμβος l παίρνει τις ιδιότητες της ρίζας του δέντρου
  
      while (l != nullptr && wd != l->data.val)  // Όσο υπάρχουν κόμβοι και η λέξη δεν βρίσκεται
      {
          if (wd > l->data.val)
              l = l->deksia;  
          else
              l = l->aristera;  
      }
      return l;  // Επιστρέφεται η ρίζα που τροποποιήθηκε παραπάνω.
}

bool BSTree::remove(string wd)  // Διαγραφή κόμβου απο BSTree
{
      node* paidi=search(wd); 
  
      if (paidi != nullptr)  // Αν ο κόμβος βρεθεί μέσα στο δέντρο
          return remove (paidi); 
      return false;
}


bool BSTree::remove(node* paidi)  // Private διαδικασία που αφαιρεί τον κόμβο (paidi) από το BSTree
{
        node* gonios;  
      
    
        if (paidi == nullptr)
            return false;
      
    
        gonios = paidi->gonios; 
      
    
        if (paidi->aristera == nullptr && paidi->deksia == nullptr) // Αν ο κόμβος είναι φύλλο.
        {
              if (gonios==nullptr)  // Αν δεν έχει γονιό (δηλαδή είναι μοναδικός κόμβος του δέντρου και η ρίζα του)
          {
              delete(paidi);  // Διαγράφεται ο κόμβος
              riza = nullptr;  // Η ρίζα ορίζεται null (κενό δέντρο)
          }
          else if (gonios->aristera == paidi)  // Αν ο κόμβος paidi είναι το αριστερό παιδί του γονιού του
          {
              delete (gonios->aristera);  // Διαγράφεται ο κόμβος
              gonios->aristera=nullptr;  // Ορίζεται το αριστερό παιδί του κόμβου σε null
          }
          else  // Αν ο κόμβος paidi είναι το δεξί παιδί του γονιού του
          {
              delete gonios->deksia;  // Διαγράφεται ο κόμβος
              gonios->deksia= nullptr;  // Ορίζεται το δεξί παιδί του κόμβου σε null
          } 
        }
        else if (paidi->aristera == nullptr || paidi->deksia == nullptr )  // Αν (paidi) έχει μόνο ένα παιδί.
        { 
          
            if (gonios==nullptr)                  // Αν είναι η ρίζα του δέντρου με ένα παιδί.
            {
                if (paidi->aristera == nullptr)       // Αν (paidi) έχει μόνο δεξί παιδί)
                    riza = paidi->deksia;          // Ορίζεται ως ρίζα το δεξί παιδί του κόμβου paidi
                else                              // Αν (paidi) έχει μόνο αριστερό παιδί)
                    riza = paidi->aristera;           // Ορίζεται ως ρίζα το αριστερό παιδί του κόμβου paidi
                delete (paidi);               
            }
            else if (gonios->aristera == paidi)       
            {
              
                if (paidi->aristera == nullptr)       // Αν ο (paidi) έχει μόνο δεξί παιδί
                    gonios->aristera = paidi->deksia;  // Ορίζεται ως αριστερό παιδί του γονιού του paidi το δεξί παιδί του paidi
                else                              // Αν  (paidi) έχει μόνο αριστερό παιδί
                    gonios->aristera = paidi->aristera;   // Ορίζεται ως αριστερό παιδί του γονιού του paidi το αριστερό παιδί του paidi
                delete (paidi);                  
            }
            else                                  // Αν ο κόμβος paidi είναι το δεξί παιδί του γονιού του
            {
                if (paidi->aristera == nullptr)       // Αν (paidi) έχει μόνο δεξί παιδί
                    gonios->deksia = paidi->deksia; // Ορίζεται ως δεξί παιδί του γονιού του paidi το δεξί παιδί του paidi
                else                              // Αν (paidi) έχει μόνο αριστερό παιδί
                    gonios->deksia = paidi->aristera;
        // Ορίζεται ως δεξί παιδί του γονιού του paidi το αριστερό παιδί του paidi
                delete (paidi);                   
    
            }
        }
        else // Αν (paidi) έχει 2 παιδία
        { 
          
            node * minimum = elaxisto(paidi->deksia);  //Βρίσκουμε τον ελάχιστο κόμβο του δεξιού υποδέντρου
            paidi->data.val = minimum->data.val;  // Η wd που έχει ο ελάχιστος κόμβος εκχωρείται στον κόμβο paidi
            paidi->data.mesTi = minimum->data.mesTi;  //Οι φορές εμφάνισης της wd του ελάχιστου κόμβου εκχωρούνται στο (paidi)
            remove(minimum);  
          
        }
        return true;
}

node* BSTree::elaxisto(node* arxh)  // Βρίσκει τον ελάχιστο κόμβο κάποιου υποδέντρου με ρίζα (arxh)
{
  
      if (arxh == nullptr) 
          return nullptr;
  
      node* l = arxh;
  
      while (l->aristera!=nullptr)  // Όσο υπάρχουν στοιχεία στο δέντρο
          l = l->aristera;  
  
      return l; 
}
