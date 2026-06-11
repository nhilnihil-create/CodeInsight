#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

int main(){
  string O,E;
  cin >> O >> E;

  for(int i=0;i<E.size();++i) cout << O.at(i) << E.at(i);
  if(O.size()!=E.size()) cout << O.at(O.size()-1);
  cout << endl;

  return 0;
}
