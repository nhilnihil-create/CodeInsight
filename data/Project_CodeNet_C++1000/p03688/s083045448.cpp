#include <bits/stdc++.h>

using namespace std;

bool solve()
{
  int N;
  cin >> N;
  int a = 0, b = 0;
  map<int, int> m;
  for (int i = 0; i < N; i++) {
    int t;
    cin >> t;
    m[t]++;
    if (a && a != t) b = t;
    else a = t;
  }
  if (m.size() > 2) return false;
  if (m.size() == 1) {
    if (a == N-1) return true;
    if (a * 2 <= N) return true;
    return false;
  }
  if (a > b) {
    swap(a, b);
  }
  if (b - a != 1) return false;
  int c = b - m[a];
  if (c <= 0) return false;
  if (c * 2 > m[b]) return false;
  return true;
}

int main()
{
  if (solve()) cout << "Yes" << endl;
  else cout << "No" << endl;
}
