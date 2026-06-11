#include <bits/stdc++.h>
using namespace std;

int main() {
  string O, E;
  cin >> O >> E;
  int o = O.size();
  int e = E.size();
  
  for(int i=0; i<e; i++){
    cout << O.at(i) << E.at(i);
  }
  
  if(o-e==1)cout << O.at(o-1);
  cout << endl;
}