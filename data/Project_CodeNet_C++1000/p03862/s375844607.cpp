#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000000LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
   ll n, x, e;
   cin >> n >> x;
   vector<ll> A(n);
   rep(i, n) cin >> A[i];
   ll res = 0;

   rep(i, n-1){
     e = max((ll)0, (A[i] + A[i+1]) - x); //減らす数
     res += e;
     A[i+1] = max((ll)0, A[i+1] - e);
   }
  cout << res << ln;

}
