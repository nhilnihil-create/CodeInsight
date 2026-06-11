#include <bits/stdc++.h>
using namespace std;

int main(){
  string a,b,c;
  cin >> a >> b >> c;
  
  int d = a.size() - 1;
  int e = b.size() - 1;
  int f = c.size() - 1;
  
  if(a.at(d) == b.at(0)) {
    if(b.at(e) == c.at(0)) {
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
  else {
    cout << "NO" << endl;
  }
}
