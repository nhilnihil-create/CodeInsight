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


int main() {
  int N; ll W; cin >>N >>W;
  vector<vector<ll>> vs(4, vector<ll>(1, 0));
  ll wmin;
  // 各々重さがwmin,wmin+1,wmin+2,wmin+3のものを格納
  rep(i, N){
    if (i == 0){
      int v; cin >>wmin >>v;
      vs[0].push_back(v);
    }else{
      int w,v; cin >>w >>v;
      vs[w-wmin].push_back(v);
    }
  }
  rep(i, 4){ sort(next(vs[i].begin()), vs[i].end()); reverse(next(vs[i].begin()), vs[i].end());}
  rep(i, 4) rep(j, vs[i].size()-1) vs[i][j+1] += vs[i][j];
  ll res = 0;
  rep(i, vs[0].size()){
    rep(j, vs[1].size()){
      rep(k, vs[2].size()){
        rep(l, vs[3].size()){
          ll weight = i*wmin + j*(wmin+1) + k*(wmin+2) + l*(wmin+3);
          if (weight > W) continue;
          chmax(res, vs[0][i] + vs[1][j] + vs[2][k] + vs[3][l]);
        }
      }
    }
  }
  cout <<res <<endl;
}
