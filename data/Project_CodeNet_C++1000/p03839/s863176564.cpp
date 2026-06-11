#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

//long long
using ll = long long;

//出力系
#define print(x) cout << x << endl
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
 
// begin() end()
#define all(x) (x).begin(),(x).end()

//for
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n, i##_len=(n); i>=0; i--)
#define FOR(i,a,b) for(int i=(a), i##_len=(b); i<i##_len; ++i)

//最大公約数 
 ll gcd(ll a,ll b){
 if(b == 0) return a;
 return gcd(b,a%b);
 }

//最小公倍数
 ll lcm(ll a,ll b){
 ll g = gcd(a,b);
 return a / g * b; // Be careful not to overflow  if(a < b) return gcd(b, a);
  unsigned r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
} 

#define INF 1LL<<60



  int main(){
    int N, K;
    cin >> N >> K;
    vector<int>a(N);
    REP(i, N) cin >> a.at(i);

    vector<ll>v(N + 1, 0);
    REP(i, N) v.at(i + 1) = v.at(i) + a.at(i);
    vector<ll>w(N + 1, 0);
    REP(i, N) w.at(i + 1) = w.at(i) + max(a.at(i), 0);
    ll ans = - INF;
    for(int i = 0; i + K <= N; i++){
      ll tmp = w.at(N);
      tmp -= w.at(i + K) - w.at(i);
      tmp += max(v.at(i + K) - v.at(i), 0ll);
      ans = max(ans, tmp);
    }
    print(ans);
  }
