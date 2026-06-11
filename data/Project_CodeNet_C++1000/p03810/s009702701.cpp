#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define f first
#define s second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define ll long long
#define ld double
#define ull unsigned long long
#define PI pair < int, int > 

const int N = 2e5 + 123;
const int M = 123;
const ld Pi = acos(-1);
const ll Inf = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;
const int Sz = 501;
const int MOD = 1e9 + 7;

void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int mult(int a, int b) {
  return 1ll * a * b % mod;
}
int sum(int a, int b) {
  add(a, b);
  return a;
}

int n, a[N], c[2];

int gcd(int a, int b) {
  while(b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

void solve() { 
  cin >> n;
  for (int i = 1;i <= n;i++) {
    cin >> a[i];
  }
  for (int it = 0;;it++) {
    bool fail = 0;
    for (int i = 1;i <= n;i++) fail |= (a[i] > 1);
    if (!fail) {
      if (it & 1) cout << "First\n";
      else cout << "Second\n";
      return; 
    }
    c[0] = c[1] = 0;
    for (int i = 1;i <= n;i++) c[a[i] & 1]++;
    if (c[0] & 1) {
      if (it & 1) cout << "Second\n";
      else cout << "First\n";
      return;
    }
    if (c[1] > 1) {
      if (it & 1) cout << "First\n";
      else cout << "Second\n";
      return;
    }
    bool ok = 0;
    for (int i = 1;i <= n;i++) {
      if (a[i] & 1) {
        if (a[i] == 1) ok = 1;
        a[i]--;
        break;
      }
    }
    if (ok) {
      if (it & 1) cout << "First\n";
      else cout << "Second\n";
      return;
    }
    int g = 0;
    for (int i = 1;i <= n;i++) g = gcd(g, a[i]);
    for (int i = 1;i <= n;i++) a[i] /= g;
    continue;
    cout << "i = " << it << " g = " << g << endl;
    for (int i = 1;i <= n;i++) cout << a[i] << " ";
    cout << endl;
  } 
}

int main() {
  #ifdef wws
   freopen("in", "r", stdin);
   // freopen("in", "w", stdout);
  #endif 
  ios_base::sync_with_stdio(0);
  int tt = 1; 
  while(tt--) solve();
  return 0;
}