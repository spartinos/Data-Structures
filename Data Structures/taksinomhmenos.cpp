  #include "taksinomhmenos.h"
  
  taksinomhmenos::taksinomhmenos()
  {
        FFC = 0;
        Array = nullptr;
  }
  
  taksinomhmenos::~taksinomhmenos()
  {
      delete[] Array;
  }
  
  void taksinomhmenos::Insert(string wd)
  {
      long long  int temporary , mesTi;
  
      if (binS(wd, 0, FFC - 1, temporary, mesTi))
          Array[temporary].mesTi++;
      else
      {
          RealocArray(1);
          Array[FFC - 1].val = wd;
          Array[FFC - 1].mesTi = 1;
          InsSort();
      }
  }
  
  void taksinomhmenos::InsSort()  
  {
      int i,j,Xronos;
      string key;
      for(i = 1; i < FFC; i++)
      {
          key = Array[i].val;
          Xronos = Array[i].mesTi;
  
          j=i-1;
  
          while(j >= 0 && Array[j].val > key)
          {
              Array[j + 1].val = Array[j].val;
              Array[j + 1].mesTi = Array[j].mesTi;
              j=j-1;
          }
  
          Array[j + 1].val = key;
          Array[j + 1].mesTi = Xronos;
      }
  }
  
  bool taksinomhmenos::Delete(string obj)
  {
      long long  int temporary, mesTi;
  
      if (!binS(obj, 0, FFC, temporary, mesTi))  // An to stoixeio periexetai ston pinaka
          return false;
  
      for (long long unsigned int position = temporary; position < FFC - 1; position++)
      {
          Array[position].val = Array[position + 1].val;
          Array[position].mesTi = Array[position + 1].mesTi;
      }
  
      FFC--;
      return true;
  }
  
  bool taksinomhmenos::RealocArray(int n)
  {
  
        Arr* temporary = new (std::nothrow) Arr[FFC + n];  // Proswrinos dunamikos pinakas me to neo megethos

    
        if (temporary == nullptr) 
            return false;

    
          for (long long unsigned int elem = 0; elem < FFC; elem++)  // Antigrafoume ta stoixeia tou pinaka
          {
            
              temporary[elem].val = Array[elem].val;
              temporary[elem].mesTi=Array[elem].mesTi;
          }
    
          delete[] Array;  
          Array = temporary;
          FFC++;  // Αυξάνουμε το μέγεθος του πίνακα
    
        return true;
  }
  
  bool taksinomhmenos::binS(string wd, long long  int aristera, long long int deksia, long long& temporary, long long &mesTi)
  {   
        if (deksia >= aristera)
        {
              long long  int mid = aristera + (deksia - aristera) / 2;
       
              if (Array[mid].val == wd)
              {
                  temporary = mid;
                  mesTi = Array[mid].mesTi;
                  return true;
              }
              if (Array[mid].val > wd)
                  return binS(wd,aristera, mid - 1,temporary , mesTi);
      
              return binS(wd,mid + 1, deksia,temporary , mesTi);
        }
        mesTi = 0;
        return false;
  }
  
  bool taksinomhmenos::Find(string wd, long long& mesTi)
  {
        long long temporary;
        return binS(wd, 0, FFC, temporary, mesTi);
  }
