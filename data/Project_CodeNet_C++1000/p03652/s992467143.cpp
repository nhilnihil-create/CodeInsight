#include <bits/stdc++.h>
#define int long long int
using namespace std;
template<typename T,typename U> using P=pair<T,U>;
template<typename T> using V=vector<T>;
template<typename T>bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}

template<typename T>auto&operator<<(ostream&s,const vector<T>&v){s<<"[";bool a=1;for(auto e:v){s<<(a?"":" ")<<e;a=0;}s<<"]";return s;}
template<typename T,typename U>auto&operator<<(ostream&s,const pair<T,U>&p){s<<"("<<p.first<<","<<p.second<<")";return s;}
template<typename T>auto&operator<<(ostream&s,const set<T>&st){s<<"{";bool a=1;for(auto e:st){s<<(a?"":" ")<<e;a=0;}s<<"}";return s;}
template<typename T,typename U>auto&operator<<(ostream&s,const map<T,U>&m){s<<"{";bool a=1;for(auto e:m){s<<(a?"":" ")<<e.first<<":"<<e.second;a=0;}s<<"}";return s;}
#define DUMP(x)  cerr<<#x<<" = "<<(x)<<endl;

struct edge { int to, cost; };

const int INF = 1e18;
const int MOD = 1e9+7;

signed main()
{
   int n, m; cin >> n >> m;
   V<queue<int>> A(n);
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         int a; cin >> a; a--;
         A[i].push(a);
      }
   }

   V<set<int>> st(m);
   for (int i = 0; i < n; i++) {
      st[A[i].front()].insert(i);
      A[i].pop();
   }

   V<bool> deleted(m, false);
   bool terminal = false;
   int ans = INF;
   while (!terminal) {
      DUMP(st)
      int maxSize = 0, maxSport = -1;
      for (int j = 0; j < m; j++) {
         if (chmax(maxSize, (int)st[j].size())) {
            maxSport = j;
         }
      }
      chmin(ans, maxSize);
      DUMP(maxSport)
      deleted[maxSport] = true;
      DUMP(deleted)
      for (auto i : st[maxSport]) {
         while (A[i].size() > 0 && deleted[A[i].front()]) {
            A[i].pop();
         }
         if (A[i].size() == 0) {
            terminal = true;
            break;
         }
         st[A[i].front()].insert(i);
      }
      st[maxSport].clear();
      DUMP(st)
      cerr << endl;
   }
   cout << ans << endl;
   return 0;
}
