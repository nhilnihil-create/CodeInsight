#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;

void answer(bool ok) {
  cout << (ok ? "Possible" : "Impossible") << endl;
  exit(0);
}
#define NO() answer(false)
#define YES() answer(true)

const int N = 105;
int a[N];
int f[N];

int main() {
#ifdef LOCAL_EXEC
//	freopen("sample.in", "r", stdin);
//	freopen("sample.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    f[a[i]]++;
  }
  sort(a, a + n);
  if (a[n - 1] != a[n - 2]) NO();

  int d = a[n - 1];
  int r = (d + 1) / 2;
  for (int x = r; x <= d; x++) {
    int cur = 2;
    if (x == r && d % 2 == 0) cur = 1;
    if (f[x] < cur) NO();
    f[x] -= cur;
  }

  for (int x = 1; x <= r; x++) {
    if (f[x]) NO();
  }

  YES();

  return 0;
}
