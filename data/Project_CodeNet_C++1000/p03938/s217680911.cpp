#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, p, a[20020], b[20020];
pair<int, int> ps[20020];

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n;

  int val = 500000000;
  for(int i = 0; i < n; ++i) {
    cin >> p;
    ps[i].first = p;
    ps[i].second = val++;
  }
  sort(ps, ps + n);

  a[0] = 1;
  b[0] = ps[0].second - a[0];
  for(int i = 1; i < n; ++i) {
    int next_a = ps[i].second - b[i-1] + 1; 
    a[i] = (next_a > a[i-1] ? next_a : a[i-1] + 1);
    b[i] = ps[i].second - a[i];
  }
  for(int i = 0; i < n; ++i) cout << a[i] << (i==n-1?'\n':' ');
  for(int i = 0; i < n; ++i) cout << b[i] << (i==n-1?'\n':' ');
  return 0;
}