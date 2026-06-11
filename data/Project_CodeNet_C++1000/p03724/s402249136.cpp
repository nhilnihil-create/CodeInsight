#include <iostream>

using namespace std;

const int MAXN = 1e5+10;

int n, m;
int a[MAXN], b[MAXN];
int cnt[MAXN];

void solve() {
  for (int i=0;i<m;i++) {
    cnt[a[i]-1]++;
    cnt[b[i]-1]++;
  }
  for (int i=0;i<n;i++) {
    if (cnt[i] % 2 == 1) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}

int main() {
  cin >> n >> m;
  for (int i=0;i<m;i++) {
    cin >> a[i] >> b[i];
  }
  solve();
}
