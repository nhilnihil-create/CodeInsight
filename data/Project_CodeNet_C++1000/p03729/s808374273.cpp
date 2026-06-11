#include <bits/stdc++.h>
using namespace std;

int main() {
  string a,b,c;
  string chk = "NO";
  
  cin >> a >> b >> c;

  if(a.at(a.size()-1) == b.at(0)){
    if(b.at(b.size()-1) == c.at(0)){
      chk = "YES";
    }
  }
  
  cout << chk;
}
