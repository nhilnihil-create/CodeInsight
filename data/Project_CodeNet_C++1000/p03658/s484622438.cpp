#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> l(n);
  rep(i, 0, n) cin >> l[i];
  int sum = 0;
  sort(l.begin(), l.end());
  rep(i, 0, k) sum += l[n-i-1];
  cout << sum << "\n";
}