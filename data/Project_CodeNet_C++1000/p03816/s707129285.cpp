#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(long long i=0; i<(int)n; i++)
#define rep2(i,a,n) for(long long i=(a); i<(int)(n); i++)
#define all(vec) vec.begin(),vec.end()
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using psi = pair<string, int>;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};
const int mod = 1e9+7;
int gcd(int a, int b){if(a%b == 0){return(b);}else{return(gcd(b, a%b));}}
int lcm(int a, int b){return a * b / gcd(a, b);}

int N, M, K, H, W, L, R, X;
//string S, T;

signed main(){
  cin >> N;
  map<int, int> mp;
  rep(i,N) { int a; cin >> a; mp[a]++; }
  int ans = 0;
  
  if(mp.size() %2 == 0) ans = mp.size()-1;
  else ans = mp.size();
  cout << ans << endl;
  return 0;
}
