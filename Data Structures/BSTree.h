  #pragma once
  
  #include <fstream>
  #include <string>
  #include "node.h"
  
  using namespace std;
  
  class BSTree
  {
  private:

        node* riza;
        node* elaxisto(node *);  // Εύρεση ελάχιστου κόμβου
        node* search(string );
        void inOrder(node*, string);
        void preOrder(node*, string);
        void postOrder(node*, string);
        void destroy(node* riza);  // Διαγράφει το δέντρο
        bool remove (node*);
        bool insert(node* riza , const string &wd);

  public:


        ~BSTree();
        BSTree();


        void Inorderprint (string);
        void Preorderprint(string);
        void Postorderprint(string);


        bool Insert(string);            
        bool search(string, long long int&);
        bool remove(string);


  };
