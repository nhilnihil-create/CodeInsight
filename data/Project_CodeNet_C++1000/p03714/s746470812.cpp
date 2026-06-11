#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
  int n; cin >> n;
  vector<ll> res(n+1);

  priority_queue<int, vector<int>, greater<int>> lque;
  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    res[0] += a;
    lque.push(a);
  }

  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    res[i+1] += res[i] + v[i];
    lque.push(v[i]);
    res[i+1] -= lque.top(); lque.pop();
  }

  ll sum = 0;
  priority_queue<int> rque;
  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    sum += a;
    rque.push(a);
  }

  ll ans = res[n] - sum;
  for (int i = n-1; i >= 0; i--) {
    sum += v[i];
    rque.push(v[i]);
    sum -= rque.top(); rque.pop();
    ans = max(ans, res[i] - sum);
  }
  cout << ans << endl;
}