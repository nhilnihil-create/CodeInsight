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


int N;
vector<ll> T, A;

void input() {
  cin >>N;
  T.assign(N, 0); A.assign(N, 0);
  rep(i, N) cin >>T[i] >>A[i];
}

int main() {
  input();
  ll a = 0, b = 0;
  rep(i, N){
    ll c = T[i], d = A[i];
    // 比が現在の得票数以上になっている
    if (a <= c && b <= d){ a = c; b = d; continue; }
    // 比が丁度一緒になってる
    if (a % c == 0 && b % d == 0 && a / c == b / d) continue;
    // 得票数と比が異なっている
    ll aa = a % c == 0 ? a : (a/c + 1) * c;
    ll bb = aa / c * d;
    if (bb >= b){
      a = aa; b = bb;
    }else{
      b = b % d == 0 ? b : (b/d + 1) * d;
      a = b / d * c;
    }
  }
  ll res = a + b;
  cout <<res <<endl;
}