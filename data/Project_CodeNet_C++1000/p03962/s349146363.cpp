#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
int main() {
  int a, b, c; cin >> a >> b >> c;
  if (a == b && b == c) cout << 1 << endl;
  else if (a != b && b != c && a != c) cout << 3 << endl;
  else cout << 2 << endl;
  
  return 0;
}
