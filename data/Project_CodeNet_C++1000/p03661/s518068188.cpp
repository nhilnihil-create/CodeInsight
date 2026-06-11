// V solo
#include <bits/stdc++.h>

#define forn(i, a, b) for (int i = a; i <= b; ++i)
#define forr(i, a, b) for (int i = a; i >= b; --i)

using namespace std;

const int N = (int)2e5 + 7;
const long long INF = 1e15 + 7;

typedef long long ll;
typedef long double ld;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

int n, a[N];
ll t[N * 4];

void build (int v, int tl, int tr){
  if (tl == tr) t[v] = a[tl];
  else {
    int tm = tl + tr >> 1;
    build (v * 2, tl, tm);
    build (v * 2 + 1, tm + 1, tr);
    t[v] = t[v * 2] + t[v * 2 + 1];
  }
}

ll get (int v, int tl, int tr, int l, int r){
  if (tl > r || tr < l) return 0;
  if (l <= tl && tr <= r) return t[v];
  int mid = tl + tr >> 1;
  return get (v + v, tl, mid, l, r) + get (v + v + 1, mid + 1, tr, l, r);
}

int main (){
  scanf ("%d", &n);
  forn (i, 1, n) scanf ("%d", a + i);
  build (1, 1, n);
  ll mn = INF;
  forn (i, 1, n - 1){
    ll cur = abs(get (1, 1, n, 1, i) - get (1, 1, n, i + 1, n));
    mn = min(mn, cur);
  }
  printf ("%lld\n", mn);
  return 0;
}
