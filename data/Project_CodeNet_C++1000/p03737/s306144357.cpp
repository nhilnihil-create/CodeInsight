#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;



  
int main() {
  string a,b,c;
  cin >>a>>b>>c;
  char dif = 'A'-'a';
  char A = a[0]+dif;
  char B = b[0]+dif;
  char C = c[0]+dif;
  cout << A << B << C << endl;
}
      