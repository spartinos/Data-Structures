#pragma once

#include <string>

using namespace std;

class taksinomhmenos
{
private:
    struct Arr
    {
        string val;
        long long unsigned int mesTi;
    };
    Arr* Array;
    long long unsigned int FFC;  // Τελευταία ελεύθερη θέση στον πίνακα
private:
    bool binS(string,long long  int,long long  int,long long int& ,long long int&);  //Binary search
    bool RealocArray(int);  // Αυξάνεται το μέγεθος του πίνακα
    void InsSort();  // Αλγόριθμος ταξινόμησης
public:
    taksinomhmenos();  //Constructor
    ~taksinomhmenos();  // Destructor

    void Insert(string);
    bool Find(string, long long&); 
    bool Delete(string);  

    long long unsigned int getFFC() 
    { 
        return FFC;
    }

    string& operator[](unsigned int pos)
    { 
        return Array[pos].val; 
    }  // Επιστρέφω συγκεκριμένο στοιχείο ανάλογα με τη θέση του.
};