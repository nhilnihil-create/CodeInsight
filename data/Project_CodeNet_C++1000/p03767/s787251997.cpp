#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const long long INF = 1LL << 60;
const int mod = 1000000007;

ll dp[100100];
int main() {
   int n;
   cin >> n;
   vector<ll> a(3*n);
   rep(i,3*n) cin >>a[i];
   ll ans =0;
   sort(a.begin(),a.end(),greater<ll>());
   for(int i = 1 ; i<2*n;i+=2){
       ans +=a[i];
   }
   cout << ans <<endl;
}