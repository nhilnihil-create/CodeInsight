#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;

int main() {
  int a,b;
  string op;
  cin >> a >> op >> b;
  if(op == "+"){
    cout << a+b << endl;
  }
  else{
    cout << a-b << endl;
  }
  
  
}
     