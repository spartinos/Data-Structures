  #pragma once
  #include <string>
  
  using std::string;
  
  class ataksinomhtos
  {
    private:
        struct Arr
        {
            string val;
            long long unsigned int mesTi;
        };
        Arr* Array;
        long long unsigned int FFC;  // Πρώτη κενή θέση
    protected:
        bool RealocArray(int);  // Αυξάνεται το μέγεθος του πίνακα
    public:
        ataksinomhtos();  // Constructor
        ~ataksinomhtos();  // Destructor
    
        void Insert(string);  
        bool Delete(string);  
        bool Find(string, long long unsigned int&,  long long unsigned int&);  // Αναζήτηση στοιχείου στον πίνακα
    
        long long unsigned int getFFC() { return FFC; }
    
        // Επιστρέφω συγκεκριμένο στοιχείο στη θέση στον πίνακα
        string& operator[](unsigned int possition) { return Array[possition].val; }
  };
