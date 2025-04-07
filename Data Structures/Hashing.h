#pragma once
#include <string>

using std::string;

class HashNode
{
public:
    HashNode(string wd, int key, int mesTi)
    {
        this->wd = wd;
        this->key = key;
        this->mesTi = mesTi;
    }
    string wd;
    unsigned int key, mesTi;
};

class Hashing
{
private:
    unsigned long long int megethos;
    unsigned long long int elems;  // Στοιχεία
    HashNode** pinakas;  
protected:
    long long getkey(const string&);  // Λέξεις->Αριθμούς
    HashNode*& Ret(const int&, const string&);  // Επιστρέφει συγκ. θέση του πίνακα.
    unsigned int Hash(const int&);  // Υπολογίζει τη θέση.
    unsigned int epomenhHash(unsigned int);  // Υπολογίζει επόμενη θέση.
public:
    Hashing();  // Constructor
    ~Hashing();  // Destructor
    bool Insert(const string&); 
    bool Find(string&, unsigned int &);
};

