#include<bits/stdc++.h>
using namespace std;

int main() {
  string a,b,c;
  cin >> a >> b >> c;
  bool flag = false;
  if(a.at(a.size()-1) == b.at(0)) {
    if(b.at(b.size()-1) == c.at(0)) flag = true;
  }
  if(flag) cout << "YES" << endl;
  else cout << "NO" << endl;
}