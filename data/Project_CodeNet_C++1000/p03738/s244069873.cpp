#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> ii;
typedef map<int, int> MPII;
typedef set<int> SETI;

const int mxN = 2e5;
const ld pi = 4.0 * atanl(1.0);
const int iinf = 1e9 + 10;
const int inf = 1e18 + iinf + 10;
const int mod = 1000000007;
const ld prec = .000001;

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(c) c.begin(), c.end()
#define rall(c) c.end(), c.begin()

void fast() { ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); }

int main() {
  fast();
  string n, m;
  cin >> n >> m;
  int a = n.length(), b = m.length();

  if (a > b) {
    cout << "GREATER";
    return 0;
  }
  if (a < b) {
    cout << "LESS";
    return 0;
  }

  for (int i = 0; i < a; ++i) {
    if (n[i] > m[i]) {
      cout << "GREATER";
      return 0;
    } else if (n[i] < m[i]) {
      cout << "LESS";
      return 0;
    }
  }
  cout << "EQUAL";

  return 0;
}
