#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL<<60;

int main()
{
  ll n;cin>>n;
  ll a[n];
  for (ll i = 0; i < n; i ++) {
    cin >> a[i];
  }

  ll minA = 0;
  ll sumA = 0;
  for(ll i=0; i < n; i ++) {
    sumA += a[i];
    // 偶数項を正とする
    if (i%2==0) {
      if (sumA <= 0) {
        minA += abs(sumA) + 1;
        sumA += abs(sumA) + 1;
      }
    } else {
      if (sumA >= 0) {
        minA += abs(sumA) +1;
        sumA -= abs(sumA) +1;
      }
    }
  }

  ll minB = 0;
  ll sumB = 0;
  for(ll i=0; i < n; i ++) {
    sumB += a[i];
    // 奇数項を正とする
    if (i%2!=0) {
      if (sumB <= 0) {
        minB += abs(sumB) + 1;
        sumB += abs(sumB) + 1;
      }
    } else {
      if (sumB >= 0) {
        minB += abs(sumB) +1;
        sumB -= abs(sumB) +1;
      }
    }
  }

  cout << min(minA, minB) << endl;
  return 0;
}