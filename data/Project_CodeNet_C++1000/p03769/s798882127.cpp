/**
 *    author:  tourist
 *    created: 11.01.2020 00:10:58       
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> Solve(long long n) {
  if (n == 0) {
    return vector<int>();
  }
  if (n % 2 == 1) {
    auto a = Solve(n / 2);
    int c = (a.empty() ? 0 : *max_element(a.begin(), a.end())) + 1;
    a.insert(a.begin() + (int) a.size() / 2, c);
    a.push_back(c);
    return a;
  }
  auto a = Solve(n - 1);
  int c = (a.empty() ? 0 : *max_element(a.begin(), a.end())) + 1;
  a.insert(a.begin() + (int) a.size() / 2, {c, c});
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  auto a = Solve(n);
  cout << a.size() << '\n';
  for (int i = 0; i < (int) a.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << a[i];
  }
  cout << '\n';
  return 0;
}
