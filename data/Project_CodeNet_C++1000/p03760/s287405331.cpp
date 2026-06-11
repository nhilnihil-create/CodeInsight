#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string o,e;
  cin >> o >> e;
  
  if ( o.size() - e.size() == 0 ){
    for ( int i = 0; i < o.size(); i++){
      cout << o[i] << e[i];
    }
    cout << endl;
  }else{
    for ( int i = 0; i < e.size(); i++){
      cout << o[i] << e[i];
    }
    cout << o[o.size()-1] << endl;
  }
   
}