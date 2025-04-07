#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include "node.h"

using namespace std;

class AVLtree
{
  private:
  
        node* riza; 
        node* rotations(node*, string wd, long long int);  // Aπαραίτητες περιστροφές.
        node* rebal(node* &, string);  // Διαμόρφωση του δέντρου σε ισοζυγισμένο.
        node* remove(node*, string);  // Διαγραφή κόμβου απο το δέντρο.
        node* elaxisto(node*);  // Επιστροφή ελάχιστου κόμβου.
        node* Rrotation(node*);  // Δεξιά περιστροφή.
        node* Lrotation(node*);  // Αριστερή περιστροφή.
        node* insert(node* , const string& );
        node* search(string);
        
        int max(int, int);
        int get_ypsos(node*);
        
        void destroy(node*);  // Διαγράφει το δέντρο.
        void inOrder (node*, string);
        void preOrder(node*, string);
        void postOrder(node*, string);
  public:
        ~AVLtree();               // Destructor.
        AVLtree();                // Constructor.
    
        void Inorderprint (string);
        void Preorderprint(string);
        void Postorderprint(string);
    
        bool Insert(string wd);          // Εισαγωγή στο απλό δυαδικό δέντρο αναζήτησης
        bool search(string wd, long long int&);
        bool remove(string wd);
};

