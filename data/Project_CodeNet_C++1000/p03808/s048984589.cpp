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

   int suma = accumulate(a.begin(), a.end(), 0LL);
   int s = (n+1) * n / 2;
   if (suma % s != 0) {
      cout << "NO" << endl;
      return 0;
   }
   int k = suma / s;

   V<int> d(n);
   for (int i = 0; i < n; i++) {
      d[i] = a[(i+1) % n] - a[i] - k;
   }

   for (int i = 0; i < n; i++) {
      if (d[i] > 0 || d[i] % n != 0) {
         cout << "NO" << endl;
         return 0;
      }
   }
   cout << "YES" << endl;


   return 0;
}
