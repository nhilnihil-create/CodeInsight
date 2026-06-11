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
   ll n, x;
   cin >> n >> x;
   vector<ll> A(n, 0);
   rep(i, n) cin >> A[i];

   vector<ll> s(n-1, 0);
   rep(i, n-1) s[i] = A[i] + A[i+1];

   ll cnt = 0;
   rep(i, n-1){
     ll num = s[i] - x; //減らす数
     if(num <= 0) continue;
     //cout << "num:"   << num << " s:" << s[i] << ln;
     if(num <= A[i+1]){
       A[i+1] -= num;
       s[i] -= num;
       s[i+1] -= num;
     } else {
       s[i] -= num;
       s[i+1] -= A[i+1];
       A[i] -= (num - A[i+1]);
       A[i+1] = 0;
     }
     cnt += num;
   }
   cout << cnt << ln;
}
