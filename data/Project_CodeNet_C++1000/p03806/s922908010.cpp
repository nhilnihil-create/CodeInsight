#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
#define PRINT(v) for (auto x : (v)) cout <<x <<" " ; cout <<endl;
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using mat = vector<vector<ll>>;
const ll MOD = 1000000007;
const ll INF = 10000000000000000;
const int inf = 1001001001;
vector<int> x4 = {0, 1, 0, -1}, x8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> y4 = {1, 0, -1, 0}, y8 = {1, 1, 0, -1, -1, -1, 0, 1};
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return 1;
T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }
template<class T> inline T power(T a,T b,T m){ if (b==0) return 1;
  T tmp = power(a,b/2,m); if (b%2==0) return tmp*tmp%m; else return tmp*tmp%m*a%m; }
template<class T> inline T gcd(T a, T b){if (b==0) return a; return gcd(b, a%b);}
template<class T> inline T lcm(T a, T b){return a / gcd(a,b) * b;}
// ax+by=gcd(a,b)を解く
template<class T> inline T extgcd(T a,T b,T &x,T &y){if (b==0){x=1; y=0; return a;} T d=extgcd(b,a%b,y,x); y -= a/b*x; return d;}
void hey(){ cout <<"hey" <<endl; }

template<class T> struct edge { int to; T cost;};


int main() {
  int N; cin >>N;
  int Ma,Mb; cin >>Ma >>Mb;
  vector<int> a(N),b(N),c(N); rep(i, N) cin >>a[i] >>b[i] >>c[i];
  vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(401, vector<int>(401, inf)));
  dp[0][0][0] = 0;
  // dp[i][aa][bb] := i番目までの薬品を使ってタイプA,Bの合計が各々aa,bbのときの、費用の最小値
  for (int i=0; i<N; i++){
    for (int j=0; j<=400; j++){
      for (int k=0; k<=400; k++){
        if (dp[i][j][k] == inf) continue;
        chmin(dp[i+1][j][k], dp[i][j][k]);
        chmin(dp[i+1][j+a[i]][k+b[i]], dp[i][j][k] + c[i]);
      }
    }
  }
  int res = inf;
  for (int i=0; i<=N; i++){
    for (int j=0; j<=400; j++){
      for (int k=0; k<=400; k++){
        if (j*Mb-k*Ma != 0) continue;
        if (i==0 || j==0 || k==0) continue;
        chmin(res, dp[i][j][k]);
      }
    }
  }
  res = res == inf ? -1 : res;
  cout <<res <<endl;
}
