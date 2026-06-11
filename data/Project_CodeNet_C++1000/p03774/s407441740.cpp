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
  cin >> N >> M; 
  vvi a(N,vi(2)), c(M,vi(2));
  rep(i,N) cin >> a[i][0] >> a[i][1];
  rep(i,M) cin >> c[i][0] >> c[i][1];
  
  rep(i,N){
    int ans = 1e18;
    int pt;
    rep(j,M){
      int len = abs(a[i][0]-c[j][0]) + abs(a[i][1]-c[j][1]);
      if (ans > len) {
        pt = j;
        ans = len;
      }
    }
    cout << pt+1 << endl;
  }
  return 0;
}