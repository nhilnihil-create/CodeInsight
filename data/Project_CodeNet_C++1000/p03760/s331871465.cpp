#include <bits/stdc++.h>
using namespace std;

int main() {
  string O, E;
  cin >> O >> E;
  int i = 0;
  if(O.size() == E.size()){
    while(i < O.size() || i < E.size()){
      cout << O.at(i) << E.at(i);
      i++;
    }
    cout << endl;
  }
  else{
    for(int j = 0; j < E.size(); j++){
      if(j == E.size() - 1) cout << O.at(j) << E.at(j) << O.at(j + 1);
      else cout << O.at(j) << E.at(j);
    }
    cout << endl;
  }
}
    