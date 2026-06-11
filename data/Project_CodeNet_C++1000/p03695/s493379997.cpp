#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  vector<int> color(8, 0);
  int free = 0;

  for (int i = 0; i < n; i++) {
    if (a[i] < 400)
      color[0]++;
    else if (a[i] < 800)
      color[1]++;
    else if (a[i] < 1200)
      color[2]++;
    else if (a[i] < 1600)
      color[3]++;
    else if (a[i] < 2000)
      color[4]++;
    else if (a[i] < 2400)
      color[5]++;
    else if (a[i] < 2800)
      color[6]++;
    else if (a[i] < 3200)
      color[7]++;
    else
      free++;
  }
  int ans(0);
  for (int i = 0; i < 8; i++) {
    if (color[i] > 0) ans++;
  }
  int min = max(ans, 1);
  int max = ans + free;

  cout << min << " " << max << endl;
}
