#include<iostream>
#include<vector>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> in(n), out(n);
  vector<int> cnt(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    cnt[a]++, cnt[b]++;
  }

  for (int i = 0; i < n; i++) {
    if (cnt[i] % 2) return cout << "NO" << endl, 0;
  }
  cout << "YES" << endl;
}