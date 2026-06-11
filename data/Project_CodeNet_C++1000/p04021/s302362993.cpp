#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int n;
  cin >> n;
  vector <pair <int, int> > a(n);
  for (int i = 0; i < n; i++) {
	  int j;
	  cin >> j;
	  a[i] = make_pair(j, i);
	}
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
	  if (i % 2 != a[i].second % 2) {
		  ans++;
		}
	}
  cout << ans / 2 << endl;
  return 0;
}
