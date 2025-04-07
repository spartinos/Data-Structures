#include "AVLtree.h"


using namespace std;


AVLtree::AVLtree()
{
  
      riza = nullptr;
  
}


AVLtree::~AVLtree()  //Destructor.
{
  
      destroy(riza);
  
}

void AVLtree::destroy(node* riza)  // Διαγραφή του AVLtree από το σωρό.
{
  
      if (riza != nullptr) 
      {
        
          destroy(riza->aristera);  // Διαγραφή του αριστερού υποδέντρου(αναδρομικά)
          destroy(riza->deksia);  // Διαγραφή του δεξιού υποδέντρου(αναδρομικά)
  
          delete (riza);
      }
    
}

int AVLtree::get_ypsos(node* riza) 
// Επιστρέφει το ύψος του υποδέντρου ρίζας (riza).
{
      if (riza == nullptr)
          return 0;
  
    
      return riza->ypsos;  // Επιστρέφουμε το ύψος του δέντρου ρίζας riza.
  
}


int AVLtree::max(int ypsos1, int ypsos2)  // Εύρεση του μέγιστου μεταξύ δύο υψών.
{
  
      return((ypsos1 > ypsos2) ? ypsos1 : ypsos2);
  
}


node* AVLtree::Rrotation(node* riza) // Δεξιά περιστροφή.

{
  
      node* neariza = riza->aristera;  // Δημιουργείται κόμβος (neariza), παίρνει τις ιδιότητες του αριστερού παιδιού της riza.
      node* paidi = neariza->deksia;  // Νέος κόμβος (paidi), παίρνει τις ιδιότητες του δεξιού παιδιού της νέας ρίζας.
  
    
      neariza->deksia = riza;  // Το δεξί παιδί της νέας ρίζας παίρνει τις ιδιότητες της ρίζας(riza).
      riza->aristera = paidi;  // Το αριστερό παιδί της ρίζας (riza) παίρνει τις ιδιότητες του παιδιού.
  
    
      // Ανανεώση των υψών των ριζών (riza και neariza) μετά την δεξιά περιστροφή.
  
      riza->ypsos = max(get_ypsos(riza->aristera), get_ypsos(riza->deksia)) + 1;
      neariza->ypsos = max(get_ypsos(neariza->aristera), get_ypsos(neariza->deksia)) + 1;
  
      return neariza; 
}


node* AVLtree::Lrotation(node* riza)  //Αριστερή περιστροφή.
{
  
      node* neariza = riza->deksia;  // Δημιουργείται κόμβος (neariza), παίρνει τις ιδιότητες του δεξιού παιδιού της riza.
      node* paidi = neariza->aristera;  // Νέος κόμβος (paidi), παίρνει τις ιδιότητες του αριστερού παιδιού της νέας ρίζας.
  
  
      neariza->aristera = riza;  // Το αριστερό παιδί της νέας ρίζας παίρνει τις ιδιότητες της ρίζας(riza).
      riza->deksia = paidi;  // Το δεξί παιδί της ρίζας riza παίρνει τις ιδιότητες του παιδιού.
  
      // Ανανεώση των υψών των ριζών (riza και neariza) μετά την αριστερή περιστροφή.
  
      riza->ypsos = max(get_ypsos(riza->aristera), get_ypsos(riza->deksia)) + 1;
      neariza->ypsos = max(get_ypsos(neariza->aristera), get_ypsos(neariza->deksia)) + 1;
  
      return neariza;
  
}

node* AVLtree::rotations(node* riza, string wd, long long int heightdiff)  //Απαραίτητες περιστροφές.
{
  
      if (heightdiff> 1 && wd < riza->aristera->data.val)
        
          return  Rrotation(riza);  // Δεξιά περιστροφή για τη ρίζα (riza) , επιστροφή ανανεωμένης τιμής.
  
      if (heightdiff > 1 && wd > riza->aristera->data.val) // Αν η wd είναι μεγαλύτερη της λέξης του αριστερού παιδιού.
      {
          riza->aristera=Lrotation(riza->aristera);  // Αριστερή περιστροφή για το υποδέντρο με ρίζα riza->aristera.
        
          return Rrotation(riza);  // Δεξιά περιστροφή για τη ρίζα (riza) και επιστρέφουμε την τιμή της.
      }

  
      if (heightdiff < -1 && wd > riza->deksia->data.val)  // Αν η wd είναι μεγαλύτερη της λέξης του δεξιού παιδιού του riza
        
          return  Lrotation(riza);  // Αριστερή περιστροφή για τη ρίζα (riza) , επιστροφή ανανεωμένης τιμής.
  
     
     if (heightdiff < -1 && wd < riza->deksia->data.val)  // Αν η wd είναι μικρότερη της λέξης του αριστερού παιδιού(deksia-aristera-rotation)
      {
          riza->deksia=Rrotation(riza->deksia);  // Δεξιά περιστροφή για το υποδέντρο με ρίζα riza->deksia.
        
          return  Lrotation(riza);  // Αριστερή περιστροφή για τη ρίζα (riza) , επιστροφή ανανεωμένης τιμής.
      }

  
      return riza;
  
}


node* AVLtree::rebal(node* &riza,string wd)
{
     
  // Ανανεώνεται το ύψος της ρίζας του κόμβου.
      riza->ypsos = 1 + max(get_ypsos(riza->aristera), get_ypsos(riza->deksia));
  
      long long int heightdiff;  
  
      if(riza->aristera ==nullptr && riza->deksia==nullptr)  // Αν η ρίζα δεν έχει παιδία.
          heightdiff = 0;
      else  // Bρίσκουμε τη διαφορά ύψους(αριστερού-δεξioύ υποδέντρου).
          heightdiff = (get_ypsos(riza->aristera) - get_ypsos(riza->deksia));
  
      if(abs(heightdiff) > 1)  // Αν η παράσταση είναι αληθής,το δέντρο δεν είναι ισοζυγισμένο.
      {
          riza = rotations(riza,wd,heightdiff);
          return riza;  // Επιστρέφουμε αυτόν τον κόμβο στο σημείο κλήσης της rebal
      }

  
      return riza;
}

bool AVLtree::Insert(string wd)
{
      riza = insert(riza,wd);
  
      if(riza == nullptr)
          return false;
      else
          return true;
}
node* AVLtree::insert(node* riza, const string &wd)
{
  
      if(riza == nullptr)
      {
          riza = new node(wd);
          return riza;
      }

  
      if (wd == riza->data.val)  
      {
          riza->data.mesTi++;
          return riza;
      }
  
      if (wd > riza->data.val)  // Αν η λέξη εισαγωγής είναι μεγαλύτερη της λέξης της ρίζας πηγαίνουμε στο δεξί υποδέντρο.
          riza->deksia = insert (riza->deksia,wd);  // Αναδρομικά για το δεξί παιδί της riza.
      else
          riza->aristera = insert (riza->aristera,wd);  // Αναδρομικά για το αριστερό παιδί της riza

  
      // Πρέπει να ελεγχθεί αναδρομικά αν ολα τα υποδέντρα είναι ισοζυγισμένα.
  
      return rebal(riza,wd);
  
}

void AVLtree::Inorderprint(string file_name)
{
      ofstream file;
  
      file.open(file_name,ios::app);
  
      file << "AVLtree In order print" << endl << endl;
      inOrder (riza,file_name);
      file << endl;
}


void AVLtree::inOrder (node* l, string file_name)
{
      if (l == nullptr) 
        return;
  
      inOrder (l->aristera,file_name); 
  
      ofstream file;
  
      file.open(file_name,ios::app); // Γράφονται μέσα στο αρχείο οι κόμβοι σε inorder.
  
      file <<"string: "<< l->data.val << ", mesTi_existed: " << l->data.mesTi<<"!"<<endl;
      inOrder (l->deksia,file_name); 
}

void AVLtree::Preorderprint(string file_name) 
{
      if(riza == nullptr)
          return;
  
      ofstream file;
  
      file.open(file_name,ios::app);
  
      file << "AVLtree Pre order print" << endl << endl;
      preOrder (riza,file_name); 
      file << endl ;
  }


void AVLtree::preOrder (node *l,string file_name)
{
      if (l == nullptr)  
          return;
  
      ofstream file;
      file.open(file_name,ios::app); // Γράφονται μέσα στο αρχείο οι κόμβοι σε preorder.
  
      file <<"string: "<< l->data.val << ", mesTi_existed: " << l->data.mesTi<<"!"<<endl;
  
      preOrder (l->aristera,file_name); 
      preOrder (l->deksia,file_name);  

}

void AVLtree::Postorderprint(string file_name)
{
      ofstream file;
      file.open(file_name,ios::app);
  
      file << "AVLtree Post order print" << endl << endl;
  
      postOrder (riza,file_name); 
      file << endl ;
}


void AVLtree::postOrder (node* l, string file_name)
{
      if (l == nullptr)  
          return;

  
      postOrder (l->aristera,file_name); 
      postOrder (l->deksia,file_name);  

  
      ofstream file;
      file.open(file_name, ios::app);  // Γράφονται μέσα στο αρχείο οι κόμβοι σε postorder.
      file <<"string: "<< l->data.val << ", mesTi_existed: " << l->data.mesTi<<"!"<<endl;
  
}


bool AVLtree::search(string wd, long long int& mesTi_existed)
{
  
      node* l = search(wd);
  
  
      if (l == nullptr)
      {
          mesTi_existed = 0;
          return false;
      }
  
      mesTi_existed= l->data.mesTi;
      return true;
}


node* AVLtree::search(string wd)
{
  
      node* l;
      l= riza;
  
      while (l != nullptr && wd != l->data.val)
      {
          if (wd > l->data.val)
              l = l->deksia;
          else
              l = l->aristera;
      }
  
      return l;
  
}

node* AVLtree::elaxisto(node* arxh)  // Βρίσκει τον ελάχιστο κόμβο κάποιου υποδέντρου με ρίζα (arxh).
{
    
  if (arxh == nullptr)
          return nullptr;
  
      node* l = arxh; 

  
      while (l->aristera!=nullptr)  // Όσο υπάρχουν στοιχεία στο δέντρο
          l = l->aristera; 
  
      return l; 
}

bool AVLtree::remove(string wd)  // Διαγραφή κόμβου.
{
  
      riza=remove (riza,wd);
  
      if(riza != nullptr)
          return true;
      else
          return false;
}

node* AVLtree::remove(node* riza, string wd)  // Αφαιρεί τον κόμβο με τη λέξη wd από το δέντρο.
{
  
      if (riza == nullptr) 
          return riza;
  
  
      if (wd < riza->data.val)  // Αν η λέξη είναι μικρότερη απο αυτή της riza
          riza->aristera = remove(riza->aristera, wd);  // Αναδρομικά η διαδικασία για το αριστερό υποδέντρο
  
  
      else if(wd > riza->data.val)  // Αν η λέξη είναι μεγαλύτερη απο αυτή της riza
          riza->deksia = remove(riza->deksia, wd);  // Αναδρομικά η διαδικασία για το δεξί υποδέντρο
  
  
      if(wd == riza->data.val)  // Αν η τιμή του κόμβου είναι ίδια με τη λέξη wd.
      {
          if(riza->aristera == nullptr && riza->deksia != nullptr)  //Ελέγχουμε αν ο κόμβος riza έχει μόνο δεξί παιδί
          {
              node* temporary = riza->deksia;  // Αντιγράφουμε σε νέο προσωρινό κόμβο τις ιδιότητες του δεξιού παιδιού του riza
              *riza = *temporary;  //Δίνουμε τις ιδιότητες του temporary στο riza.
              delete(temporary);
          }
          if(riza->deksia == nullptr && riza->aristera != nullptr) // Ελέγχουμε αν ο κόμβος riza έχει μόνο αριστερό παιδί
          {
              node* temporary = riza->aristera;  // Αντιγράφουμε σε νέο προσωρινό κόμβο τις ιδιότητες του αριστερού παιδιού του riza
              *riza = *temporary;  // Δίνουμε τις ιδιότητες του temporary στο riza.
              delete(temporary);
          }
          if(riza->aristera == nullptr && riza->deksia == nullptr)  // Αν ο κόμβος είναι φύλλο.
              riza = nullptr;
  
          else  // Αν ο κόμβος που ελέγχουμε έχει 2 παιδία τοτε,
          {
              node* temporary = elaxisto(riza->deksia);  //Βρίσκουμε τον κόμβο με τη μικρότερη τιμή στο δεξί υποδέντρο του riza
              riza->data.val = temporary->data.val;  
              riza->data.mesTi = temporary->data.mesTi;
  
              riza->deksia = remove(riza->deksia, temporary->data.val);  // Αναδρομικά την delete για να διαγράψουμε τον ελάχιστο κόμβο του δεξιού υποδέντρου ρίζας riza
          }
      }
  
      if (riza == nullptr)  // Αν έχουμε κενό δέντρο επιστρέφουμε τη ρίζα χωρίς να γίνει επαναζυγισμός του δέντρου.
          return riza;
  
      return rebal(riza,wd);  // Ισοζυγίζουμε αν χρειαστεί.
}
