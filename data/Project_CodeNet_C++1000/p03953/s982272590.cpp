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

V<int> power(V<int> s, int k) {
   int n = s.size();
   V<int> res(n);
   for (int i = 0; i < n; i++) res[i] = i;

   while (k > 0) {
      if (k & 1) {
         V<int> tmp(res);
         for (int i = 0; i < n; i++) {
            res[i] = tmp[s[i]];
         }
      }
      k >>= 1;
      V<int> tmp(s);
      for (int i = 0; i < n; i++) {
         s[i] = tmp[tmp[i]];
      }
   }

   return res;
}

signed main()
{
   int n; cin >> n;
   V<int> x(n);
   for (int i = 0; i < n; i++) {
      cin >> x[i];
   }
   int m, k; cin >> m >> k;
   V<int> a(m);
   for (int i = 0; i < m; i++) {
      cin >> a[i];
      a[i]--;
   }

   V<int> s(n-1);
   for (int i = 0; i < n-1; i++) {
      s[i] = i;
   }
   for (int i = 0; i < m; i++) {
      swap(s[a[i]-1], s[a[i]]);
   }

   s = power(s, k);

   V<int> d(n-1);
   for (int i = 0; i < n-1; i++) {
      d[i] = x[i+1] - x[i];
   }

   int sum = 0;
   for (int i = 0; i < n; i++) {
      cout << x[0] + sum << endl;
      if (i != n-1) sum += d[s[i]];
   }

   return 0;
}
