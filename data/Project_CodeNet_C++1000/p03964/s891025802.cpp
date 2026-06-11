#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
  ll n;
  cin >> n;
  vector<P> votes(n);
  rep(i,n) cin >> votes[i].first >> votes[i].second;
  ll tsum, asum;
  tsum = votes[0].first;
  asum = votes[0].second;
  rep(i,n-1) {
    ll T = votes[i+1].first;
    ll A = votes[i+1].second;
    ll cnt = max(tsum/T,asum/A);
    ll t = T*cnt;
    ll a = A*cnt;
    while(t<tsum || a<asum) {
      cnt++;
      t = T*cnt;
      a = A*cnt;
    }
    tsum = t;
    asum = a;
  }
  cout << tsum + asum << endl;
  return 0;
}