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
  int n, m;
  cin >> n;

  int totaltime = 0;
  vi tn;
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    tn.pb(k);

    totaltime += k;
  }

  cin >> m;
  vii dr;
  for (int i = 0; i < m; ++i) {
    int pi, xi;
    cin >> pi >> xi;
    dr.pb(mp(pi, xi));
  }

  for (int i = 0; i < m; ++i) {
    int p = dr.at(i).first-1;
    int x = dr.at(i).second;
    cout << totaltime-tn.at(p)+x << endl;
  }
  return 0;
}
