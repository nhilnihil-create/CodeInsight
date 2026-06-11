#include <bits/stdc++.h>
using namespace std;

int main() {
  string a,b;
  cin >> a >> b;
  for (int i=0 ; i< b.size() ; i++){
    cout << a.at(i) << b.at(i) ;
  }
  if ( a.size() > b.size()){
    cout << a.at(a.size()-1) ;
  }
  cout << endl;
}
