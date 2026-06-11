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
   V<int> a(7);
   for (int i = 0; i < 7; i++) {
      cin >> a[i];
   }
   int ans = (a[0] - a[0]%2) + a[1] + (a[3] - a[3]%2) + (a[4] - a[4]%2);
   if (a[0]%2 == 1 && a[3]%2 == 1 && a[4]%2 == 1) {
      ans += 3;
   } else if (a[0] > 0 && a[3]%2 == 1 && a[4]%2 == 1) {
      ans += 1;
   } else if (a[0]%2 == 1 && a[3] > 0 && a[4]%2 == 1) {
      ans += 1;
   } else if (a[0]%2 == 1 && a[3]%2 == 1 && a[4] > 0) {
      ans += 1;
   }
   cout << ans << endl;

   return 0;
}
