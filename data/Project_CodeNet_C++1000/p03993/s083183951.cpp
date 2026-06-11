#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i < n + 1; i++) {
    cin >> a[i];
  }
  int count = 0;
  /*   for (int i = 1; i < n + 1; i++) {
      if (a[i] == a[a[i]]) {
        count++;
      }
    } */

  for (int i = 1; i < n + 1; i++) {
    for (int j = i + 1; j < n + 1; j++) {
      if (a[i] == j && a[j] == i) count++;
    }
  }

  cout << count << endl;
}