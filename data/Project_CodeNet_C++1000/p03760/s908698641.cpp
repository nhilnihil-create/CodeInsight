#include <bits/stdc++.h>
using namespace std;

int main() {
  string O,E;

  cin >> O >> E;
  for(int i=0;i<O.size();++i){
    cout << O.at(i);
    if(i < E.size()) cout << E.at(i);
  }
  cout << endl;
  return 0;
}
