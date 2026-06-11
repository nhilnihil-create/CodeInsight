#include <bits/stdc++.h>
using namespace std;;
#define ll long long
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define INF 1<<30
#define LINF 1LL<<62
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
const int MOD = 1000000007;
 
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
struct UnionFind{
    vector<int> data;
    UnionFind(int size) : data(size, -1) {}
    bool unionset(int x, int y){
        x = root(x); y = root(y);
        if(x!=y){
            if(data[y]< data[x]) swap(x,y);
            data[x] += data[y]; data[y] = x;
        }
        return x!=y;
    }
    bool find(int x, int y){
        return root(x) == root(y);
    }
    int root(int x){
        return data[x]<0 ? x : data[x] = root(data[x]);
    }
    int size(int x){
        return -data[root(x)];
    }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,k,l; cin >> n >> k >> l;
  UnionFind UF(n);
  REP(i,k){
      int p,q; 
      cin >> p >> q;p--; q--;
      UF.unionset(p,q);
  }
  UnionFind UF2(n);
  REP(i,l){
      int r,s;
      cin >> r >> s; r--; s--;
      UF2.unionset(r,s);
  }
  REP(i,n){
      UF2.root(i);
  }
  map<P, int> m;
  REP(i,n){
      int a = UF.root(i);
      int b = UF2.root(i);
      m[mp(a,b)]++;
  }
  REP(i,n){
      int a = UF.root(i);
      int b = UF2.root(i);
      cout << m[mp(a,b)] << " ";
  }

}
