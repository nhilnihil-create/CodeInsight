#ifndef Local
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 2e4 + 5;

int perm[N];
int a[N];
int b[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> perm[i];
  }

  for (int i = 1; i <= n; ++i) {
    a[i] = i * N;
    b[i] = (n - i + 1) * N;
  }

  for (int i = 1; i < n; ++i) {
    int x = perm[i];
    int y = perm[i + 1];
    int delta = max((a[x] + b[x]) - (a[y] + b[y]) + 1, 0);
    a[y] += delta / 2;
    b[y] += (delta + 1) / 2;
  }

  for (int i = 1; i <= n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
  for (int i = 1; i <= n; ++i) {
    cout << b[i] << " ";
  }
  cout << endl;
}
