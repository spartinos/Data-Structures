#include "node.h"

  node::node(const string& wd)
  {
        data.val = wd;
        data.mesTi = 1;
        aristera = nullptr;
        deksia = nullptr;
        gonios = nullptr;
        ypsos = 1;
  }

  node::node()
  {
        aristera = nullptr;
        deksia = nullptr;
        gonios = nullptr;
        ypsos = 0;
  }
