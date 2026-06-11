#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define rep(i, f, n) for (int i = (f); i < (int)(n); i++)
#define repe(i, f, n) for (int i = (f); i <= (int)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

const int INF = 1001001001;

int main() {
  string S;
  cin >> S;
  for (int i = S.size() - 2; i > 0; i -= 2) {
    string s = S.substr(0, i);
    int n = s.size();

    string s1 = s.substr(0, n / 2);
    string s2 = s.substr(n / 2, n);
    if (s1 == s2) {
      cout << n << endl;
      return 0;
    }
  }

  return 0;
}
