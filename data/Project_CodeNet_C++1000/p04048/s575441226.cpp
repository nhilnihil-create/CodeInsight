#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
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
template<class T> T gcd(T a, T b){if (b==0) return a; return gcd(b, a%b);}
template<class T> T lcm(T a, T b){return a / gcd(a,b) * b;}


int main() {
  ll n,x; cin >>n >>x;
  ll res = n;
  ll a = x, b = n-x;
  // 長さがx,n-xの平行四辺形になる
  while (true){
    if (a < b) swap(a,b);
    res += a/b * 2 * b;
    a = a%b;
    if (a == 0){
      res -= b; break;
    }
  }
  cout <<res <<endl;
}
