
#include <string.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define REP1(i,n) for(int i=1;i<=(n);++i)

#define SORT(V) sort((V).begin(), (V).end())

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

int N, K, L;
int a[2000001];
int b[2000001];
int p[1000001];
int q[1000001];
int rs[2000001];

int root(int* a, int x) {
  if (a[x] == x) {
    return x;
  } else {
    return a[x] = root(a, a[x]);
  }
}

void unite(int*a, int x, int y) {
  x = root(a, x);
  y = root(a, y);
  if (x == y) return;
  a[x] = y;
}

int main() {
  cin >> N >> K >> L;
  REP1(i, N) {
    a[i] = i;
    b[i] = i;
  }
  REP(i, K) {
    int p, q;
    cin >> p >> q;
    unite(a, p, q);
  }
  //cout << "hoge\n";
  //  REP1(i, N) {cout << a[i].root << endl;}
  REP(i, L) {
    int p, q;
    cin >> p >> q;
    unite(b, p, q);
  }
  // return 0;
  //  REP1(i, N) cout << rs[i] << endl;
  map<pair<int, int>, int> c;
  REP1(i, N) {
    c[make_pair(root(a, i), root(b, i))]++;
  }
  REP1(i, N) {
    cout << c[make_pair(root(a, i), root(b, i))] << " ";
  }
  cout << endl;
}
