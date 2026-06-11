#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  string o, e;
  cin >> o >> e;
  for (int i = 0; i < e.size(); i++) {
    cout << o[i] << e[i];
  }
  if (o.size() != e.size()) cout << o[o.size() - 1];
  cout << endl;
  return 0;
}