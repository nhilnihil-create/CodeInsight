#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,int> pli;
typedef pair<int,int> pii;
#define rep(i,a,b) for(ll i=a ; i<b ; i++)
#define qrep(que, ite) for(auto ite=begin(que) ; ite!=end(que) ; ite++)
const int max_n = 1e5;
const ll mod = 1e9+7;
const ll INF = 1LL<<60;
const int inf = 1e5;
//typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
ll mo = 998244353;
struct UnionFind {
    vector<int> par;

    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x) {
        return -par[root(x)];
    }
};
int n,m;
int d[100][100],d2[100][100];
vector<int> a,b,c;
int warshall(){
  int cnt=0;
  rep(k,0,n)rep(i,0,n)rep(j,0,n){
    chmin(d[i][j], d[i][k]+d[k][j]);
  }
  rep(i,0,m){
    if(d[a[i]][b[i]]<c[i]) cnt++;
  }
  return cnt;
}
int main(){
  cin >> n >> m;
  a.resize(m);  b.resize(m);  c.resize(m);
  rep(i,0,n)rep(j,0,n){
    d[i][j]=inf;
    d2[i][j]=inf;
    if(i==j) d[i][j]=d2[i][j]=0;
  }
  rep(i,0,m){
    int x,y,z;  cin >> x>>y>>z;
    --x;  --y;
    d[x][y] = d[y][x] = z;
    d2[x][y] = d2[y][x] = z;
    a[i]=x; b[i]=y; c[i]=z;
  }
  cout << warshall() << endl;
  return 0;
}
