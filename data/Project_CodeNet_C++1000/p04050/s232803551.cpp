#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  deque<int> odd, even;
  for (int i = 0; i < m; ++i) {
    int a;
    cin >> a;
    (a & 1 ? odd : even).push_back(a);
  }
  int k = odd.size();
  if (k > 2) return cout << "Impossible\n", 0;
  if (k > 0) even.push_front(odd[0]);
  if (k > 1) even.push_back(odd[1]);
  for (int i = 0; i < m; ++i) {
    cout << even[i] << (i != m - 1 ? ' ' : '\n');
  }
  if (m == 1) even.push_front(0);
  ++even[0];
  if (--even.back() == 0) even.pop_back();
  m = even.size();
  cout << m << '\n';
  for (int i = 0; i < m; ++i) {
    cout << even[i] << (i != m - 1 ? ' ' : '\n');
  }
}