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
  int H, W; cin >> H >> W;
  vector<string> S(H);
  rep(i,H) {string t; cin >> t; S[i]=t;}
  rep(i,H)  cout << S[i] << endl << S[i] << endl;
  
  return 0;
}