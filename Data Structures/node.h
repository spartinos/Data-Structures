#pragma once

  #include <string>
  
  using std::string;
  
  struct infonode
  {
        string val;
        long long int mesTi;
  };
  
  class node
  {
    public:
        infonode data;
        long long int ypsos;
        node* aristera;
        node* deksia;
        node* gonios;
        node(const string &);
        node();
  };
