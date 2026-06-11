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
   int N, L, T; cin >> N >> L >> T;
   V<int> X(N), W(N);
   for (int i = 0; i < N; i++) {
      cin >> X[i] >> W[i];
   }
   DUMP(X)
   DUMP(W)

   V<P<int,int>> Y(N);
   for (int i = 0; i < N; i++) {
      if (W[i] == 1) {
         Y[i].first = (X[i] + T) % L;
      } else {
         Y[i].first = (((X[i] - T) % L) + L) % L;
      }
      Y[i].second = i;
   }
   DUMP(Y)
   sort(Y.begin(), Y.end());
   DUMP(Y)

   map<int,int> cnt;
   for (int i = 0; i < N; i++) {
      cnt[Y[i].first]++;
   }
   P<int,int> y;
   for (auto it = cnt.begin(); it != cnt.end(); ++it) {
      if (it->second == 1) {
         y = make_pair(it->first, 0);
         break;
      }
   }
   int idx = lower_bound(Y.begin(), Y.end(), y)->second;
   int Y_idx = lower_bound(Y.begin(), Y.end(), y) - Y.begin();
   DUMP(idx)
   DUMP(Y_idx)

   int sum = 0;
   for (int i = 0; i < N; i++) if (W[idx] != W[i]) {
      int d = (X[i] - X[idx] + L) % L;
      if (W[idx] == 2) {
         d = (L - d) % L;
      }
      if (2 * T >= d) {
         (sum += (2 * T - d) / L + 1) %= N;
      }
      DUMP(sum)
   }
   if (W[idx] == 2) {
      sum = (N - sum) % N;
   }
   DUMP(sum)


   V<int> ans(N);
   for (int i = 0; i < N; i++) {
      ans[(i+idx+sum)%N] = Y[(i+Y_idx)%N].first;
   }
   for (int i = 0; i < N; i++) {
      cout << ans[i] << (i == N-1 ? "\n" : " ");
   }
   DUMP(ans)

   return 0;
}
