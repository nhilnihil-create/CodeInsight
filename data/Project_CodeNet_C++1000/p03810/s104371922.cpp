#include <iostream>
#include <iosfwd>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <cctype>
#include <climits>
#include <vector>
#include <bitset>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include <complex>
#include <fstream>
#include <functional>
#include <numeric>
#include <utility>
#include <algorithm>
#include <assert.h>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector <long long> vll;
typedef pair <long long, long long> pll;
typedef pair <int, int> pii;
typedef vector <int> vii;
typedef complex <double> Point;

#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mp make_pair
#define fst first
#define snd second

long long t, n, m, u, v, q, k;
const int N = 2e5 + 500;
const int LN = 21;
const long long mod = 1e9 + 7;
const long long INF = 1LL << 61LL;
long long arr[N];


int gcd(int a, int b) {
  while (a && b) {
    if (a > b) a %= b;
    else b %= a;
  }
  return a + b;
}
bool go() {
  int odd = 0, even = 0;
  for (int i = 1; i <= n; ++i) {
    if (arr[i] & 1) odd++;
    else even++;
  }
  if (even & 1) {
    // the state of even integers goes from odd to even to odd.... until 1 1 1 1 1..1
    return true;
  }
  if (odd >= 2) {
    // we'll end up at the above case with opponent playing
    return false;
  }
 // cout << odd << " " << even << endl;
  int x = 1;
  int g = 0;
  for (int i = 1; i <= n; ++i) {
    if (arr[i] & 1) x = i;
  }
  //cout << arr[x] << endl;
  if (arr[x] <= 1) return false;
  arr[x]--;
  for (int i = 1; i <= n; ++i) {
    g = gcd(g, arr[i]);
  }
  for (int i = 1; i <= n; ++i) arr[i] /= g;
  
  return 1 - go();
}
int main() {
  csl;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
  
  if (go()) {
    cout << "First\n";
  } else cout << "Second\n";
  return 0;
}
















