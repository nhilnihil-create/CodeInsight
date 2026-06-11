
#include <bits/stdc++.h>

#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


int main() {
  ll x;
  cin >> x;

  ll lb = 0, ub = x;
  while (ub-lb > 1) {
    ll mid = (lb+ub)/2;
    if (mid*(mid+1)/2 >= x) ub = mid;
    else lb = mid;
  }

  cout << ub << endl;
  return 0;
}
