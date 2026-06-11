#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

inline vector<ll> sieve(ll n){
  vector<ll> PrimeNumber;
  for(ll i = 1; i*i <= n; i++){
    if(n % i == 0){
      PrimeNumber.push_back(i);
      PrimeNumber.push_back(n/i);
    }
  }
  sort(all(PrimeNumber));
  return PrimeNumber;
}

inline int digit(ll x){
  int cnt = 0;
  while(0 < x){
    x /= 10;
    cnt++;
  }
  return cnt;
}

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  ll n; cin >> n;
  vector<ll> res = sieve(n);
  int ans = INF;
  int k = res.size();
  for(int i = 0; i < k/2; i++){
    chmin(ans,max(digit(res[i]),digit(res[k-i-1])));
  }
  cout << ans;
  cout << "\n";
  return 0;
}
