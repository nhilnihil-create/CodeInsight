#include <bits/stdc++.h>
#define int long long int
#define MOD(x) ((x % MOD_N) + MOD_N) % MOD_N
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define RFORE(i,a,b) for(int i=(b);i>=(a);--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(c) (c).begin(),(c).end()
#define RALL(c) (c).rbegin(),(c).rend()
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(RALL(c))
#define SZ(c) (int)((c).size())
#define EACH(i,v) for(auto i=v.begin();i!=v.end();++i)
#define REACH(i,v) for(auto i=v.rbegin();i!=v.rend();++i)
#define LB(c,x) distance((c).begin(),lower_bound(ALL(c),x))
#define UB(c,x) distance((c).begin(),upper_bound(ALL(c),x))
#define COUNT(c,x) (lower_bound(ALL(c),x)-upper_bound(ALL(c),x))
#define UNIQUE(c) SORT(c); (c).erase(unique(ALL(c)),(c).end());
#define COPY(c1,c2) copy(ALL(c1),(c2).begin())
#define EXIST(s,e) (bool)((s).find(e)!=(s).end())
#define PB push_back
#define MP make_pair
#define DUMP(x)  cerr<<#x<<" = "<<(x)<<endl;
#define NL cerr<<endl;
using namespace std;
template<typename T,typename U> using P=pair<T,U>;
template<typename T> using V=vector<T>;
template<typename T>bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}
template<typename T>T sum(vector<T>&v){return accumulate(ALL(v),T());}
template<typename T>T sum(vector<T>&v,int a,int b){return accumulate(v.begin()+a,v.begin()+b,T());}
template<typename T>T max(vector<T>&v){return *max_element(ALL(v));}
template<typename T>T min(vector<T>&v){return *max_element(ALL(v));}
template<typename T>T max_index(vector<T>&v){return distance((v).begin(),max_element(ALL(v)));}
template<typename T>T min_index(vector<T>&v){return distance((v).begin(),min_element(ALL(v)));}

struct edge { int to, cost; };

template<typename T>auto&operator<<(ostream&s,const vector<T>&v){s<<"[";bool a=1;for(auto e:v){s<<(a?"":" ")<<e;a=0;}s<<"]";return s;}
template<typename T,typename U>auto&operator<<(ostream&s,const pair<T,U>&p){s<<"("<<p.first<<","<<p.second<<")";return s;}
template<typename T>auto&operator<<(ostream&s,const set<T>&st){s<<"{";bool a=1;for(auto e:st){s<<(a?"":" ")<<e;a=0;}s<<"}";return s;}
template<typename T,typename U>auto&operator<<(ostream&s,const map<T,U>&m){s<<"{";bool a=1;for(auto e:m){s<<(a?"":" ")<<e.first<<":"<<e.second;a=0;}s<<"}";return s;}

const int INF = 1e18;
const int MOD_N = 1e9+7;

template<typename T> class BIT {
   private:
      vector<T> bit;
      int len;
   public:
      BIT(int n) : len(n+1), bit(n+1) {}
      void add(int i, T x) {
         i += 1;
         while (i < len) {
            bit[i] += x;
            i += i & -i;
         }
      }
      T sum(int i) {
         i += 1;
         T s = 0;
         while (i > 0) {
            s += bit[i];
            i -= i & -i;
         }
         return s;
      }
};
template<typename T> class CircleRAQ {
   private:
      BIT<T> bit;
      int mod;
   public:
      CircleRAQ(int n, int mod_n=MOD_N) : bit(n), mod(mod_n) {}
      void add(int l, int r, int x) {
         bit.add(l, x);
         bit.add((r+1) % mod, -x);
         if (l > (r+1) % mod) bit.add(0, x);
      }
      T val(int i) {
         return bit.sum(i);
      }
};

signed main()
{
   int n, m; cin >> n >> m;
   V<int> a(n);
   REP(j, n) {
      cin >> a[j]; a[j]--;
   }
   int mod = m;

   V<int> dist(n-1);
   REP(j, n-1) {
      dist[j] = (((a[j+1] - a[j]) % mod) + mod) % mod;
   }
   DUMP(dist)

   V<int> cost(m);
   REP(j, n-1) {
      int d = (((0 - a[j]) % mod) + mod) % mod;      // distance to the favorite point 0
      if (d == 0 || dist[j] < d) {
         cost[0] += dist[j];
      } else {
         cost[0] += dist[j] - d + 1;
      }
   }

   CircleRAQ<int> diff(m, mod);
   REP(j, n-1) {
      if (dist[j] == 0) continue;

      diff.add(a[j+1], a[j+1], dist[j]-1);
      diff.add((a[j]+1) % mod, (((a[j+1]-1) % mod) + mod) % mod, -1);
   }


   REP(i, m-1) {
      cost[i+1] = cost[i] + diff.val(i);
   }
   DUMP(cost)
   SORT(cost);
   cout << cost[0] << endl;

   return 0;
}
