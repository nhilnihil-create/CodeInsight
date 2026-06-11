#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <cstdlib>

using namespace std;
typedef long long int ll;

bool debug;
#define show(x) if (debug) {cout << "" # x << " = " << x << endl;}
#define rep(x, a, b) for (int x = a; x < b; x++)

int main(int argc, char **argv)
{
  (void)argv; debug = argc > 1;

  int n, m;
  cin >> n >> m;

  const int xmax = 200000;
  vector<int> xs(xmax, 0);

  rep (i, 0, n) {
    int x; cin >> x;
    xs[x]++;
  }

  vector<int> left(m, 0), margin(m, 0);
  rep (i, 0, xmax) {
    left[i % m] += xs[i] % 2;
    margin[i % m] += xs[i] / 2;
  }

  int finleft = 0;

  if (debug) {
    rep (i, 0, m) {
      cout << "margin[" << i << "] = " << margin[i] << endl;
    }
    rep (i, 0, m) {
      cout << "left[" << i << "] = " << left[i] << endl;
    }
  }

  rep (i, 1, (m + 1)/2) {
    show(i);
    if (left[i] > left[m - i]) {
      if(debug) cout << "fuga" << endl;
      int l = left[i] - left[m - i];
      finleft += l % 2 + max(2 * (l / 2 - margin[m - i]), 0);
    } else if (left[m - i] > left[i]) {
      if(debug) cout << "pohe" << endl;
      int l = left[m - i] - left[i];
      show(l);
      show(l % 2 + max(2 * (l / 2 - margin[i]), 0));
      finleft += l % 2 + max(2 * (l / 2 - margin[i]), 0);
    }
  }

  show(finleft);

  finleft += left[0] % 2;
  if (m % 2 == 0) {
    finleft += left[m/2] % 2;
  }

  cout << (n - finleft)/2 << endl;

  return 0;
}
