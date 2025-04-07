  #include "Hashing.h"
  
  Hashing::Hashing()
  {
        megethos = 100;
        elems = 0;
    
        pinakas = new HashNode*[megethos];  
        for(int i = 0;i < megethos; i++)  
            pinakas[i] = nullptr;
  }
  
  Hashing::~Hashing() //Destructor
  {
        delete[] pinakas; 
        pinakas = nullptr;
        elems = 0;
        megethos = 0;
  }
  
  unsigned int Hashing::Hash(const int& k)
  {
        return k % megethos;
  }
  
  unsigned int Hashing::epomenhHash(unsigned int k)
  {
        return (k + 1) % megethos;
  }
  
  bool Hashing::Insert(const string& wd)
  {
        int key = getkey(wd);
    
        if (Ret(key, wd) != nullptr)
            return false;
    
        if (elems * 2 >= megethos)  // Περίπτωση που το μισό του πίνακα γέμισε
        {   
            
              megethos *= 2;
              HashNode **temporary;
      
              // Νέος ARRAY τύπου HashNode με την νέα θέση που θέλω
              temporary = new (std::nothrow) HashNode*[megethos];
              for (int i = 0; i < megethos; i++)
                  temporary[i] = nullptr;  
    
            // Αντιγράφω τις θέσεις του πίνακα στον προσωρινό
            for (int i = 0; i < megethos / 2; i++)
            {
                if (pinakas[i] != nullptr)
                {
                    unsigned int p = Hash(pinakas[i]->key);
    
                    while (temporary[p] != nullptr)
                        p = epomenhHash(p);
    
                    temporary[p] = pinakas[i];
                    pinakas[i] = nullptr;
                }
            }
    
            delete[] pinakas;  
            pinakas = temporary; 
        }
        unsigned int HashIndex = Hash(key);
        while (pinakas[HashIndex] != nullptr)   // Η θέση κρατείται απο άλλη μεταβλητή
            HashIndex = epomenhHash(HashIndex);  // Ξανά-ελέγχουμε
    
        pinakas[HashIndex] = new HashNode(wd, key, 0); elems++;
        return true;
  }
  
  HashNode*& Hashing::Ret(const int& k, const string& wd)
  {
        unsigned int l = Hash(k);
        while (pinakas[l] != nullptr) // Ελέγχουμε αν η θέση είναι κενή
        {
            if (pinakas[l]->wd == wd) 
            {
                pinakas[l]->mesTi++;  // (πλήθος εμφανίσεων)++
                return pinakas[l];
            }
    
            l = epomenhHash(l);
        }
    
        return pinakas[l];
  }
  
  bool Hashing::Find(string& wd, unsigned int &mesTi)
    {
        int key = getkey(wd);
        HashNode* l = Ret(key, wd);  // Θέση με τις ιδιότητες του πίνακα που ψάχνω

      
        if (l == nullptr)
            return false;

      
        mesTi = l->mesTi; 
        wd = l->wd;
    
        return true;
  }
  
  long long Hashing::getkey(const string& s)
  {
        const int l = 31;
        const int m = 1e9 + 9;
        long long hashval = 0;
        long long ppow = 1;
  
      // Για κάθε χαρακτήρα της λέξης, εκτελούνται πράξεις με βάση μια συνάρτηση
      //  Η κάθε πράξη με γράμμα πραγματοποιείται με βάση την θέση που έχουν τα γράμματα στον πίνακα ASCII.
       for (char c : s) 
       {
        hashval = (hashval + (c - 'a' + 1) * ppow) % m;
        ppow = (ppow * l) % m;
    }
  
      return hashval;
  }