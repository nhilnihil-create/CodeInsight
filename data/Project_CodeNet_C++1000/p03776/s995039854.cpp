#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
#define allR(v) v.rbegin(), v.rend()
#define PRINT(v) for (auto x : (v)) cout <<x <<" " ; cout <<endl;
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
typedef pair<int,int> Pi;
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


ll combination(ll n, ll r){
  // nCr を そのまま求める
  map<int,int> S;
  for (int i=n-r+1; i<=n; i++){
    int x = i;
    for (int j=2; j<=50; j++){
      while (x % j == 0){
        S[j]++; x /= j;
      }
    }
  }
  for (int i=1; i<=r; i++){
    int x = i;
    for (int j=2; j<=50; j++){
      while (x % j == 0){
        S[j]--; x /= j;
      }
    }
  }
  ll res = 1;
  for (auto p : S){
    ll k = p.first;
    int v = p.second;
    // k^v;
    for (int i=0; i<v; i++) res *= k;
  }
  return res;
}

int main() {
  int N,A,B; cin >>N >>A >>B;
  vector<ll> V(N); rep(i, N) cin >>V[i];
  sort(allR(V));
  // 降順ソート
  // 上からA個見た時の平均が最大値となる
  double avg = 0;
  rep(i, A) avg += V[i];
  avg /= A;
  cout <<fixed <<setprecision(12) <<avg <<endl;

  // で、何通りあるかは上からA個のうち最小のV[i]がいくつあるかによって決定する
  int vin = 0, vout = 0;
  for (int i=0; i<N; i++){
    if (V[i] == V[A-1]){
      if (i < A) vin++;
      else vout++;
    }
  }
  // A個取るとすると答えは, n = vin + vout, r = vin として nCr
  ll n = vin + vout;
  ll r = min(vin, vout);
  ll res = combination(n, r);
  
  // 新しくとるやつが平均に一致するなら次の作業を行う
  if (V[A-1] != (ll)avg){
    cout <<res <<endl; return 0;
  }

  // A+1個以上取るとする。新しく取るやつが平均
  for (int i=A+1; i<=B; i++){
    vin++; vout--;
    n = vin + vout;
    r = min(vin, vout);
    if (vout < 0) break;
    res += combination(n,r);
  }
  cout <<res <<endl;
}