#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int v[3], ans[] = {5,5,7};

  for (int i = 0; i < 3; i++)
    cin >> v[i];

  sort(v, v + 3);

  int cnt = 0;
  for (int i = 0; i < 3; i++)
    cnt += v[i] == ans[i];

  cout << (cnt == 3 ? "YES" : "NO") << endl;

  return 0;
}
