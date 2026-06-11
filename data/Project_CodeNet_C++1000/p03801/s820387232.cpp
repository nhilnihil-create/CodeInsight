#include <bits/stdc++.h>


using namespace std;

long long n, a[100002], v[100002], ans[100002];
vector<int>p;

int main()
{
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    a[i] = v[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = n; i >= 1; i--) {
    while (!p.empty() && v[i] >= v[p.back()])
      p.pop_back();
    p.push_back(i);
  }
  p.push_back(0);
  int poz = n;
  for (int i = 0; i < p.size() - 1;i++) {
    ans[p[i]] += (v[p[i]] - v[p[i + 1]]) * (n - poz);
    while (poz > 0 && a[poz] > v[p[i + 1]]) {
      ans[p[i]] += (a[poz] - v[p[i + 1]]);
      poz--;
    }
  }
  for (int i = 1; i <= n; i++)
    cout << ans[i] << "\n";
  return 0;
}
