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
  vector<ll> a(3);
  cin >>a[0] >>a[1] >>a[2];
  sort(all(a));
  set<pair<pair<int,int>,int>> S;
  S.insert({{a[0], a[1]}, a[2]});
  ll res = 0;
  while (true){
    if (a[0] % 2 == 1 || a[1] % 2 == 1 || a[2] % 2 == 1){
      cout <<res <<endl; return 0;
    }
    ll aa = a[1]/2 + a[2]/2;
    ll bb = a[0]/2 + a[2]/2;
    ll cc = a[0]/2 + a[1]/2;
    a[0] = aa; a[1] = bb; a[2] = cc;
    sort(all(a));
    if (S.count({{a[0],a[1]},a[2]})){
      cout <<-1 <<endl; return 0;
    }
    S.insert({{a[0],a[1]},a[2]});
    res++;
  }
}
