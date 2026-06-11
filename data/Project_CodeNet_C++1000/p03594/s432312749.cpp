#include <bits/stdc++.h>
using namespace std;
using LL = long long;

template<typename T>bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}

template<typename T> vector<T> make_v(size_t a) { return vector<T>(a); }
template<typename T,typename... Ts> auto make_v(size_t a,Ts... ts) { return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...)); }

template<typename T> void fill_all(T& arr, const T& v) { arr = v; }
template<typename T, typename U> void fill_all(T& arr, const U& v) { for (auto& i : arr) fill_all(i, v); }

template<typename T>auto&operator<<(ostream&s,const vector<T>&v){s<<"[";bool a=1;for(auto e:v){s<<(a?"":" ")<<e;a=0;}s<<"]";return s;}
template<typename T,typename U>auto&operator<<(ostream&s,const pair<T,U>&p){s<<"("<<p.first<<","<<p.second<<")";return s;}
template<typename T>auto&operator<<(ostream&s,const set<T>&st){s<<"{";bool a=1;for(auto e:st){s<<(a?"":" ")<<e;a=0;}s<<"}";return s;}
template<typename T,typename U>auto&operator<<(ostream&s,const map<T,U>&m){s<<"{";bool a=1;for(auto e:m){s<<(a?"":" ")<<e.first<<":"<<e.second;a=0;}s<<"}";return s;}
#define DUMP(x) cout<<#x<<" = "<<(x)<<endl

struct edge { int to, cost; };

const LL LINF = 1LL<<60;
const int IINF = 1<<30;
const LL MOD = 1e9+7;

int main()
{
   int H, W, d; cin >> H >> W >> d;

   vector<char> cs{ 'R', 'Y', 'G', 'B' };

   auto s = make_v<int>(H, W);

   for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
         int x = i+j, y = i-j;
         while (y < 0) y += 2*d;
         (x /= d) %= 2;
         (y /= d) %= 2;
         s[i][j] = x*2 + y;
      }
   }

   for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
         cout << cs[s[i][j]];
      }
      cout << endl;
   }

   return 0;
}
