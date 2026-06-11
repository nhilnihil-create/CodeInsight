#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb(x) push_back(x)
#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> point;

const int mod = 1e9 + 7, inf = 1e9, MAXN = 1e5 + 5, off = 1 << 17;

int add(int x, int y) {x += y; if(x >= mod) return x - mod; return x;}
int sub(int x, int y) {x -= y; if(x < 0) return x + mod; return x;}
int mul(int x, int y) {return (ll) x * y % mod;}

struct Tournament{
  ll t[2 * off], p1[2 * off], p2[2 * off];
  Tournament(){ REP(i, 2 * off) t[i] = p1[i] = p2[i] = 0; }
  ll sum(ll x){
    return x * (x + 1) / 2;
  }
  void prop(int x, int lo, int hi){
    if(p1[x] == 0 && p2[x] == 0) return;
    t[x] += (hi - lo) * p2[x];
    t[x] += sum(hi - lo) * p1[x];

    if(x < off){
      p1[x * 2] += p1[x];
      p1[x * 2 + 1] += p1[x];
      p2[x * 2] += p2[x];
      p2[x * 2 + 1] += p2[x] + p1[x] * (hi - lo) / 2;
    }
    p1[x] = p2[x] = 0;
  }
  void construct(int x, int lo, int hi){
    prop(x, lo, hi);
    if(x >= off) return;
    int mid = (lo + hi) >> 1;
    construct(x * 2, lo, mid); construct(x * 2 + 1, mid, hi);
  }
  void update(int x, int lo, int hi, int a, int b, int tip, int val){
    if(lo >= hi) return;
    prop(x, lo, hi);
    if(lo >= b || hi <= a) return;
    if(lo >= a && hi <= b){
      if(tip == 0){
        p2[x] += val;
      }
      else{
        p1[x] --;
        p2[x] -= (lo - a);
        p2[x] += val;
      }
      prop(x, lo, hi);
      return;
    }
    int mid = (lo + hi) >> 1;
    update(x * 2, lo, mid, a, b, tip, val); update(x * 2 + 1, mid, hi, a, b, tip, val);
  }
} T;

int n, m;
int a[MAXN];

int dist(int x, int y){
  if(x <= y) return y - x;
  return ( m - (x - y) );
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> n >> m;
  REP(i, n) cin >> a[i];
  FOR(i, 1, n){
    int d = dist(a[i - 1], a[i]);
    //TRACE(d);
    if(a[i - 1] <= a[i]){
      T.update(1, 0, off, a[i - 1] + 1, a[i] + 1, 1, d + 1);
      //cout << a[i - 1] + 1 _ a[i] + 1 _ d << "\n";
      T.update(1, 0, off, a[i] + 1, m + 1, 0, d);
      T.update(1, 0, off, 1, a[i - 1] + 1, 0, d);
    }
    else{
      T.update(1, 0, off, a[i - 1] + 1, m + 1, 1, d + 1);
      T.update(1, 0, off, 1, a[i] + 1, 1, dist(0, a[i]) + 1);
      T.update(1, 0, off, a[i] + 1, a[i - 1] + 1, 0, d);
    }
    //T.construct(1, 0, off);
    //FOR(i, 1, m + 1) cout << T.t[i + off] << " ";
    //cout << "\n";
  }
  T.construct(1, 0, off);
  ll sol = 1e18;
  FOR(i, 1, m + 1) sol = min(sol, T.t[i + off]);
  cout << sol;
}
