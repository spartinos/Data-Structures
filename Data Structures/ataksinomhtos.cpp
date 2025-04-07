  #include "ataksinomhtos.h"
  
  
  using namespace std;
  
  
  ataksinomhtos::ataksinomhtos()
  {
    
        FFC = 0;
        Array = nullptr;
    
  }
  
  
  ataksinomhtos::~ataksinomhtos()
  {
    
        delete[] Array;
    
  }
  
  
  void ataksinomhtos::Insert(string wd)
  {
    
        long long unsigned int temporary, mesTi;
      
        if(Find(wd,temporary ,mesTi))
          
            Array[temporary].mesTi++;
          
        else
        {
          
            RealocArray(1);
            Array[FFC - 1].val = wd;
            Array[FFC - 1].mesTi = 1;
          
        }
  }
  
  bool ataksinomhtos::Delete(string obj)
  {
    
        long long unsigned int temporary, mesTi;
      
        if (!Find(obj,temporary, mesTi)) 
          // An to stoixeio uparxei ston pinaka
            return false;
      
    
        for (long long unsigned int pos = temporary; pos < FFC - 1; pos++)
        {
          
            Array[pos].val = Array[pos + 1].val;  // Μετάθεση λέξεων μία θέση πίσω
            Array[pos].mesTi = Array[pos + 1].mesTi;  // Μετάθεση φορών εμφάνισης μία θέση πίσω
        }
    
        Array[FFC - 1].mesTi = 1;
        FFC--;
    
        return true;
    
  }
  
  bool ataksinomhtos::Find(string obj, long long unsigned int& temporary, long long unsigned int& mesTi)
  {
    
        if(FFC == 0)
          
            return false;
    
        for (unsigned long long int i = 0; i < FFC; i++)  // Σειριαρκή αναζήτηση
        {
          
            if(Array[i].val == obj)
            {
              
                temporary = i;
                mesTi = Array[i].mesTi;
                return true;
              
            }
          
        }
    
        mesTi = 0;
      
        return false;
    
  }
  
  bool ataksinomhtos::RealocArray(int n)
  {
    
        Arr* temporary = new (std::nothrow) Arr[FFC + n];
    
        if (temporary == nullptr) 
            return false;
    
        for (long long unsigned int elem = 0; elem < FFC; elem++)  
        {
          
            temporary[elem].val = Array[elem].val;
            temporary[elem].mesTi= Array[elem].mesTi;
          
        }
    
        delete[] Array;  
      
        Array = temporary;  
      
        FFC++; // Αυξάνουμε το μέγεθος
      
        return true;
    
  }