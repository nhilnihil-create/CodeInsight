#include <bits/stdc++.h>

using namespace std;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int get_cnt(int la, int totala, int lb, int totalb){

  if(la > lb){
    swap(la, lb);
    swap(totala, totalb);
  }

  if(lb <= totala){
    return (totala + totalb)/2;
  }else{
    return totala + (totalb-lb)/2;
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  vector<int> back(100100);

  rep(i, n){
    int x;
    cin >> x;
    back[x]++;
  }

  vector<pair<int, int>> cntm(m);

  rep(i, 100001){
    cntm[i%m].first += back[i] % 2;
    cntm[i%m].second += back[i];
  }

  int ans = 0;
  ans += cntm[0].second/2;
  if(m % 2 == 0){
    ans += cntm[m/2].second/2;
  }

  for(int i = 1; i < (m+1)/2; i++){
    ans += get_cnt(cntm[i].first, cntm[i].second, cntm[m-i].first, cntm[m-i].second);
  }

  cout << ans << endl;

  return 0;
}
