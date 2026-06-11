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
   int n, K; cin >> n >> K;
   vector<LL> A(n), B(n);
   for (int i = 0; i < n; ++i) {
      cin >> A[i] >> B[i];
   }


   vector<LL> C(32);

   for (int i = 0; i < n; ++i) {
      if (A[i] > K) continue;
      for (int j = 30; j >= 0; --j) {
         if ((K >> j & 1) == 0 &&
             (A[i] >> j & 1) == 1) {
            break;
         }
         if ((K >> j & 1) == 1 &&
             (A[i] >> j & 1) == 0) {
            C[j+1] += B[i];
         }
      }
      if ((A[i] & ~K) == 0) {
         C[0] += B[i];
      }
   }

   cout << *max_element(C.begin(), C.end()) << endl;

   return 0;
}
