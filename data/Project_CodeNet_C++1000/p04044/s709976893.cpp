#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);  

  int n, l;

  cin >> n >> l;

  vector<string> v(n);

  for (int i = 0; i < n; i++)
    cin >> v[i];

  sort(v.begin(), v.end());

  for (auto s : v)
    cout << s;
  cout << endl;

  return 0;
}
