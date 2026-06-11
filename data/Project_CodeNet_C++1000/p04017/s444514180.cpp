#include <bits/stdc++.h>
using namespace std;

const int K = 20;
int n, q, l;
int x[100000];
int d[K][100000];
void pre() {
  int j = 0;
  for (int i = 0; i < n; ++i) {
    while (j < n && x[j] - x[i] <= l) {
      ++j;
    }
    d[0][i] = j - 1;
  }
  
  for (int k = 1; k < K; ++k) {
    for (int i = 0; i < n; ++i) {
      d[k][i] = d[k - 1][d[k - 1][i]];
    }
  }
}

int sub(int a, int b) {
  int cnt = 0;
  int i = a;
  for (int k = K - 1; k >= 0; --k) {
    int ni = d[k][i];
    if (ni < b) {
      cnt += 1 << k;
      i = ni;
    }
  }
  return cnt + 1;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> x[i];
  cin >> l >> q;
  pre();
  
  for (int j = 0; j < q; ++j) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    if (a > b) swap(a, b);
    cout << sub(a, b) << endl;
  }
}