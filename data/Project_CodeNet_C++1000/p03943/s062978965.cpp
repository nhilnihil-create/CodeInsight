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
  vi ame(3);
  rep(i,3) { int a; cin >> a; ame[i]=a;}
  sort(all(ame));
  if( ame[2] == ame[0]+ame[1]) cout << "Yes" << endl;
  else cout << "No" << endl;  
  
  return 0;
}
