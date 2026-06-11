#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;

int main() {
  set<int>S;
  int a,b,c;
  cin >> a >> b >> c;
  S.insert(a);
  S.insert(b);
  S.insert(c);
  
  cout << S.size() << endl;
}
      
       