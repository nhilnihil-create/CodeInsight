#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
typedef long long ll;

int main() {
  int x = 0;
  int n;
  cin >> n;
  string s;
  cin >> s;

  int res = 0;
  for (char c : s) {
    if (c == 'I') {
      x++;
      res = max(res, x);
    } else {
      x--;
    }
  }

  cout << res << endl;
  return 0;
}
