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
   int n; cin >> n;
   V<int> a(n);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }

   map<int,int> cnt;
   for (int i = 0; i < n; i++) cnt[a[i]]++;

   int maxa = *max_element(a.begin(), a.end());
   int mina = *min_element(a.begin(), a.end());
   if (maxa % 2 == 0) {
      if (cnt[maxa / 2] != 1) {
         cout << "Impossible" << endl;
         return 0;
      }
      for (int i = maxa / 2 + 1; i <= maxa; i++) {
         if (cnt[i] < 2) {
            cout << "Impossible" << endl;
            return 0;
         }
      }
      if (mina < maxa / 2) {
         cout << "Impossible" << endl;
         return 0;
      }
   } else {
      if (cnt[(maxa+1) / 2] != 2) {
         cout << "Impossible" << endl;
         return 0;
      }
      for (int i = (maxa+1) / 2 + 1; i <= maxa; i++) {
         if (cnt[i] < 2) {
            cout << "Impossible" << endl;
            return 0;
         }
      }
      if (mina < (maxa+1) / 2) {
         cout << "Impossible" << endl;
         return 0;
      }
   }

   cout << "Possible" << endl;

   return 0;
}
