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
   int H, W, h, w; cin >> H >> W >> h >> w;

   if (H % h == 0 && W % w == 0) {
      cout << "No" << endl;
      return 0;
   }

   V<V<int>> A(H, V<int>(W));
   if (H % h != 0) {
      for (int j = 0; j < W; j++) {
         V<int> s(H+1, 1e5);
         s[0] = 0;
         for (int i = 0; i+h <= H; i++) {
            s[i+h] = s[i] - 1;
         }
         for (int i = 0; i < H; i++) {
            A[i][j] = s[i+1] - s[i];
         }
      }
   }
   else if (W % w != 0) {
      for (int i = 0; i < H; i++) {
         V<int> s(W+1, 1e5);
         s[0] = 0;
         for (int j = 0; j+w <= W; j++) {
            s[j+w] = s[j] - 1;
         }
         for (int j = 0; j < W; j++) {
            A[i][j] = s[j+1] - s[j];
         }
      }
   }

   cout << "Yes" << endl;
   for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
         cout << A[i][j] << (j == W-1 ? "\n" : " ");
      }
   }

   return 0;
}
