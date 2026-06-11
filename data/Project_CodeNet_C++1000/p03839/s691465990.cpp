#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;

ll arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, K;
  cin >> n >> K;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // include some substring, positives from the rest
  ll cur = 0;
  for (int i = 0; i < K; i++) {
    cur += arr[i];
  }
  for (int i = K; i < n; i++) {
    cur += max(0LL, arr[i]);
  }

  ll ans = cur;
  for (int i = K; i < n; i++) {
    cur -= max(0LL, arr[i]);
    cur += arr[i];

    cur -= arr[i - K];
    cur += max(0LL, arr[i - K]);

    ans = max(ans, cur);
  }

  // exclude some substring, positives from the rest
  cur = 0;
  for (int i = K; i < n; i++) {
    cur += max(0LL, arr[i]);
  }
  ans = max(ans, cur);

  for (int i = K; i < n; i++) {
    cur -= max(0LL, arr[i]);
    cur += max(0LL, arr[i - K]);
    ans = max(ans, cur);
  }

  cout << ans << endl;
}
