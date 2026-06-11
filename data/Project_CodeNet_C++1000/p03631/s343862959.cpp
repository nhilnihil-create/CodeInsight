#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define rep(i,n) for(ll i = 0; i < n; i++)

int main() {
  ll n;
  cin >> n;
  if (n/100 == n%10) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  return 0;
}