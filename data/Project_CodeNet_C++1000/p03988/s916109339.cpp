// template version 1.11
using namespace std;
#include <iostream>
#include <bits/stdc++.h>

// varibable settings {{{
#define infile "../test/sample-1.in"
#define int long long
const int INF=1e18;
const int MOD=1e9+7;
// }}}

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
#include "/home/koji0708/go/src/github.com/kjnh10/pcl/template/codes/lib/dump.hpp"
#else
#define dump(...) 42
#define dump_1d(...) 42
#define dump_2d(...) 42
#endif
//}}}

int solve(){
  int n;cin>>n;
  vector<int> a(n);
  map<int, int> cnt;
  int M = -1;
  rep(i, n) {
    cin>>a[i];
    cnt[a[i]]++;
    chmax(M, a[i]);
  }
  sort(all(a));
  dump(a);
  dump(cnt);

  int m = INF;
  rep(i, (M+2-1)/2){
    dump(i);
    chmin(m, M-i);
    if (!(cnt[M-i]>=2)) {
      cout << "Impossible" << endl;
      return 0;
    }
    else{
      cnt[M-i] -= 2;
    }
  }
  if (M%2==0) {
    chmin(m, M/2);
    dump(M/2);
    if (!(cnt[M/2]>=1)) {
      cout << "Impossible" << endl;
      return 0;
    }
    else{
      cnt[M/2] -= 1;
    }
  }
  dump(m);
  dump(cnt);

  //他の項は最小値+1以上であることが必要
  each(el, cnt){
    int v = el.first;
    int num = el.second;
    if (v <= m && num > 0){
      cout << "Impossible" << endl;
      return 0;
    }
  }
  cout << "Possible" << endl;
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
