// template version 1.12
using namespace std;
#include <iostream>
#include <bits/stdc++.h>

// varibable settings
#define infile "../test/sample-1.in"
#define int long long //{{{
const int INF=1e18;
const int MOD=1e9+7; //}}}

// define basic macro {{{
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define _rrep(i,n) rrepi(i,0,n)
#define rrepi(i,a,b) for(int i=(int)((b)-1);i>=(int)(a);--i)
#define rrep(...) _overload3(__VA_ARGS__,rrepi,_rrep,)(__VA_ARGS__)
#define each(i,a) for (auto&& i : a)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define ceil(a,b) ((a)+(b)-1)/(b)
#define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())
#define ub upper_bound
#define lb lower_bound
#define posl(A, x) (lower_bound(all(A), x)-A.begin())
#define posu(A, x) (upper_bound(all(A),x)-A.begin())
template<class T> inline void chmax(T &a, const T &b) { if((a) < (b)) (a) = (b); }
template<class T> inline void chmin(T &a, const T &b) { if((a) > (b)) (a) = (b); }

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef pair<int,int> pii;
typedef tuple<int,int,int> iii;

template<typename T> using PQ = priority_queue<T, vector<T>, greater<T>>;
struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false); } } fast;

#if defined(PCM) || defined(LOCAL)
  #include "lib/dump.hpp"
#else
  #define dump(...) 42
  #define dump_1d(...) 42
  #define dump_2d(...) 42
#endif
//}}}

int solve(){
  int n,m;cin>>n>>m;
  vvi a(n, vi(m));
  rep(i,n){
    rep(j,m){
      cin>>a[i][j];
    }
  }
  vi now(n);

  int ans = INF;
  set<int> removed;
  while(true){
    dump(now);
    map<int, int> cnt;
    rep(i, n){
      cnt[a[i][now[i]]]++;
    }
    dump(cnt);
    int M = -INF;
    each(el, cnt){
      int sp = el.first;
      int v = el.second;
      dump(sp, v);
      chmax(M, v);
    }
    dump(M);
    chmin(ans, M);
    each(el, cnt){
      int sp = el.first;
      int v = el.second;
      if (v==M) {
        removed.insert(sp);
        dump(sp);
        rep(i, n){
          while (removed.find(a[i][now[i]])!=removed.end()){
            now[i]++;
            if (now[i]==m) {
              cout << ans << endl;
              return 0;
            }
          }
        }
        break;
      }
    }
  }
  return 0;
}

signed main() { //{{{
#ifdef INPUT_FROM_FILE
  std::ifstream in(infile);
  std::cin.rdbuf(in.rdbuf());
#endif
  solve();
  return 0;
} //}}}
