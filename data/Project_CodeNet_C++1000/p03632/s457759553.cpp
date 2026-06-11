#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long ll;
#define SortAsc(c) std::sort(c.begin(), c.end())
#define SortDesc(c) std::sort(c.rbegin(), c.rend())
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  int w = min(B, D) - max(A, C);
  if (C > B || A > D) {
    w = 0;
  }
  if (w < 0) {
    w = 0;
  }
  cout << w << endl;
}