#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
long double const pi = std::acos(-1.0L);


int main() {
  string a, b;
  cin >> a >> b;
  if(a.size()==b.size()){
    if(a>b) cout << "GREATER" << endl;
    else if(a<b) cout << "LESS" << endl;
    else cout << "EQUAL" << endl;
  }
  else if(a.size()>b.size()) cout << "GREATER" << endl;
  else cout << "LESS" << endl;
    
    return 0;
}