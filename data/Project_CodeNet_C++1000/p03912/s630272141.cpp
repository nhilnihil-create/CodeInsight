// template version 1.12
using namespace std;
#include <iostream>
#include <bits/stdc++.h>

// varibable settings
#define infile "../test/sample-2.in"
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
  vector<int> x(n);

  vector<int> cnt(100001);
  rep(i, n) {
    cin>>x[i];
    cnt[x[i]]++;
  }
  dump(x);

  int ans = 0;
  rep(i, m){
    if (i<(m-i)%m){
      multiset<int> st1, st2;
      int s1 = 0;
      int s2 = 0;
      int o1 = 0;
      int o2 = 0;
      for(int j=i; j<100001; j+=m){
        if (cnt[j]>0){
          st1.insert(cnt[j]);
          s1 += cnt[j];
          if (cnt[j]%2==1) o1++;
        }
      }
      for(int j=m-i; j<100001; j+=m){
        if (cnt[j]>0){
          st2.insert(cnt[j]);
          s2 += cnt[j];
          if (cnt[j]%2==1) o2++;
        }
      }
      dump(i, m-i, st1, st2, o1, o2);

      if (o1==o2){
        ans += (s1+s2)/2;
      }
      else {
        if (o2 < o1){
          swap(s1,s2);
          swap(o1,o2);
        }

        if (s1-o1>=o2-o1){
          ans += (s1+s2)/2;
        }
        else{
          ans += ((s1+s2)-(o2-s1))/2;
        }
      }
    }
    else if (i==(m-i)%m){
      int num = 0;
      for(int j=i; j<100001; j+=m){
        num += cnt[j];
      }
      ans += num/2;
    }
    dump(i, ans);
  }
  cout << ans << endl;
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
