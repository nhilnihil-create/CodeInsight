#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> P;
typedef long long ll;

int main()
{
  int N;

  cin >> N;
  vector<int> a(3 * N);
  for (int i = 0; i < 3 * N; i++) {
    cin >> a[i];
  }

  vector<ll> dsum(N + 1, 0);
  priority_queue<int, vector<int>, greater<int>> dpq;
  vector<ll> lsum(N + 1, 0);
  priority_queue<int> lpq;
  for (int i = 0; i < N; i++) {
    dsum[0] += a[i];
    dpq.push(a[i]);

    lsum[0] += a[2 * N + i];
    lpq.push(a[2 * N + i]);
  }
  for (int i = 1; i <= N; i++) {
    dsum[i] = dsum[i - 1] + a[N + i - 1];
    dpq.push(a[N + i - 1]);
    dsum[i] -= dpq.top(); dpq.pop();

    lsum[i] = lsum[i - 1] + a[2 * N - i];
    lpq.push(a[2 * N - i]);
    lsum[i] -= lpq.top(); lpq.pop();
  }

  ll ans = -110000000000000;
  for(int i = 0; i <= N; i++) {
    ans = max(ans, dsum[i] - lsum[N - i]);
  }
  cout << ans << endl;

  return 0;
}

