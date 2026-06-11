#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e15 + 7;
int si[] = {-1, 0, 1, 0};
int sj[] = {0, -1, 0, 1};

int main() {
  int n;
  cin >> n;
  vector<ll> a(3*n);
  rep(i,3*n) cin >> a[i];

  priority_queue<ll,vector<ll>,greater<ll>> q1;
  ll s1 = 0;
  rep(i,n){
    q1.push(a[i]);
    s1 += a[i];
  }

  vector<ll> v1;
  v1.push_back(s1);
  for (int k = n; k < 2*n; k++){
    if (q1.top() < a[k]){
      s1 -= q1.top();
      s1 += a[k];
      q1.pop();
      q1.push(a[k]);
    }
    v1.push_back(s1);
  }

  priority_queue<ll> q2;
  ll s2 = 0;
  for (int i = 2*n; i < 3*n; i++) {
    q2.push(a[i]);
    s2 += a[i];
  }

  vector<ll> v2;
  v2.push_back(s2);
  for (int k = 2*n-1; k > n-1; k--){
    if (q2.top() > a[k]){
      s2 -= q2.top();
      s2 += a[k];
      q2.pop();
      q2.push(a[k]);
    }
    v2.push_back(s2);
  }

  reverse(v2.begin(), v2.end());

  ll ans = -1 * M;
  rep(i,v1.size()) ans = max(ans, v1[i]-v2[i]);
  cout << ans << endl;

  return 0;
}
