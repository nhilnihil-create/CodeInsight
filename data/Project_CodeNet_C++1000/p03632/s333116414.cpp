#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;



int main() {
 int a,b,c,d;
  cin >>a>>b>>c>>d;
  cout << max(0,min(b,d)-max(a,c)) << endl;
}
     