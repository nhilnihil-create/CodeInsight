#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
const int INF = 1e9;

int main() {
  vector<int> vec(3);
  cin >> vec[0] >> vec[1] >> vec[2];
  sort(vec.begin(), vec.end());
  if (vec[0] + vec[1] == vec[2]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
