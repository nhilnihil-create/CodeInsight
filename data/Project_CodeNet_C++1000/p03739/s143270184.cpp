#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
#define PRINT(v) for (auto x : (V)) cout <<x <<" " <<endl;
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll MOD = 1000000007;
const ll INF = 10000000000000000;
vector<int> x4 = {0, 1, 0, -1}, x8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> y4 = {1, 0, -1, 0}, y8 = {1, 1, 0, -1, -1, -1, 0, 1};
template<class T> struct edge { int from, to; T cost;};
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


int main() {
  int n; cin >>n;
  vector<ll> a(n); rep(i, n) cin >>a[i];
  ll res1 = 0;
  ll res2 = 0;
  ll sum = 0;
  // 和が正負正負… か 負正負正… になるかで場合分け
  for (int i=0; i<n; i++){
    sum += a[i];
    // iが偶数なら和が正になるようにする
    if (i%2==0) if (sum <= 0){ res1 += 1 - sum; sum = 1; }
    // i が奇数なら和が負になるようにする
    if (i%2==1) if (sum >= 0){ res1 += sum - (-1); sum = -1; }
  }
  sum = 0;
  for (int i=0; i<n; i++){
    sum += a[i];
    if (i%2==0) if (sum >= 0){ res2 += sum - (-1); sum = -1; }
    if (i%2==1) if (sum <= 0){ res2 += 1 - sum; sum = 1; }
  }
  ll res = min(res1, res2);
  cout <<res <<endl;

}
