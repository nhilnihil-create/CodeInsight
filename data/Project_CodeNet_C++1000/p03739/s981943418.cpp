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
  vll a(n);
  rep(i,n) cin >> a.at(i);
  ll sum = 0;
  ll cnt1 = 0;
  rep(i,n) {
    if(i%2==0) {
      sum += a[i];
      if(sum>0) continue;
      else {
        cnt1 += (1-sum);
        sum = 1;
      }
    }
    else {
      sum += a[i];
      if(sum<0) continue;
      else {
        cnt1 += (sum+1);
        sum = -1;
      }
    }
  }
  sum = 0;
  ll cnt2 = 0;
  rep(i,n) {
    if(i%2==1) {
      sum += a[i];
      if(sum>0) continue;
      else {
        cnt2 += (1-sum);
        sum = 1;
      }
    }
    else {
      sum += a[i];
      if(sum<0) continue;
      else {
        cnt2 += (sum+1);
        sum = -1;
      }
    }
  }
  cout << min(cnt1,cnt2) << endl;
  return 0;
}