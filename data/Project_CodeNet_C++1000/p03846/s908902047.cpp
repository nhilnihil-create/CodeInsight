#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
template <typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template <typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int INT_INF = 1LL << 30;
#define MOD 1000000007

template <typename T>
ll beki(T x, ll n){
  T res = 1;
  while(n > 0){
    if(n & 1){
      res *= x%MOD;
      res %= MOD;
    }
    x = x * x % MOD;
    n >>= 1;
  }
  return res;
}

int main(){
  ll N;
  cin >> N;
  vll box1(0), box2(0);
  for(int i = 0; i < N; i++){
    ll A;
    cin >> A;
    box1.push_back(A);
  }

  sort(ALL(box1), greater<ll>());

  for(int i = N-1; i >= 0; i-=2){
    box2.push_back(i);
    if(i != 0) box2.push_back(i);
  }

  if(box1 == box2) cout << beki(2LL, N/2) << endl;
  else cout << 0 << endl;
}