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
  if (Ma > Mb){
    swap(Ma, Mb); swap(a, b);
    // 問題をMa <= Mb の場合に帰着する
  }
  vector<vector<int>> dp(N+1, vector<int>(8001, inf));
  for (int i=0; i<N; i++) dp[i+1][b[i]*Ma-a[i]*Mb+4000] = c[i];
  // Ma : Mb = A : B <=> Ma*B = A*Mb
  // X = B*Ma - A*Mb とすると
  // Xが取りうる値は
  //   最小値：40 * 1 * 1 - 40*10*10 = 40 * (-99) > -4000
  //   最大値：40 * 10 *10 - 40*1*9   = 40 * 91 < 4000
  // よって Y = X + 4000 とすれば
  // 0 <= Y <= 8000 としてよい
  // dp[i][Y] := i番目までの薬品を使って, 選んだai, bi の合計をA, B としたとき Y = B*Ma - A*Mb + 4000 とする。
  //             このときの予算の最小値
  // 求めたいものはdp[N][4000]
  for (int i=0; i<N; i++){
    for (int Y=0; Y<=8000; Y++){
      if (dp[i][Y] == inf) continue;
      chmin(dp[i+1][Y], dp[i][Y]);
      // dY = (nB*Ma - nA*Mb + 4000) - (B*Ma - A*Mb + 4000)
      //    = (nB-B)*Ma - (nA-A)*Mb
      //    = b[i]*Ma - a[i]*Mb
      chmin(dp[i+1][Y + b[i]*Ma - a[i]*Mb], dp[i][Y] + c[i]);
    }
  }
  int res = dp[N][4000] == inf ? -1 : dp[N][4000];
  cout <<res <<endl;
}
