#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

vector<int> PermutationProduct(const vector<int>& p, const vector<int>& q) {
  int n = p.size();
  vector<int> r(n);
  for (int i = 0; i < n; i++) {
    r[i] = p[q[i]];
  }
  return r;
}

vector<int> PermutationPower(const vector<int>& p, int64 k) {
  int n = p.size();

  if (k == 0) {
    vector<int> r(n);
    for (int i = 0; i < n; i++) r[i] = i;
    return r;
  }
  
  if (k == 1) {
    return p;
  }
  
  if (k % 2 == 1) {
    vector<int> q = PermutationPower(p, k - 1);
    return PermutationProduct(p, q);
  } else {
    vector<int> q = PermutationPower(p, k / 2);
    return PermutationProduct(q, q);
  }
}

vector<int> PermutationInverse(const vector<int>& p) {
  int n = p.size();
  vector<int> r(n);
  for (int i = 0; i < n; i++) {
    r[p[i]] = i;
  }
  return r;
}

void DumpVector(vector<int> xs) {
  for (int x : xs) {
    cout << x << " ";
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // vector<int> r({1, 2, 3, 4, 0});
  // DumpVector(PermutationPower(r, 0));
  // DumpVector(PermutationPower(r, 1));
  // DumpVector(PermutationPower(r, 2));
  // DumpVector(PermutationPower(r, 3));
  // DumpVector(PermutationPower(r, 4));
  // DumpVector(PermutationPower(r, 5));

  int n;
  cin >> n;
  vector<int64> xs(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
  }
  vector<int64> ds(n - 1);
  for (int i = 0; i < n - 1; i++) {
    ds[i] = xs[i + 1] - xs[i];
  }

  vector<int> p(n - 1);
  for (int i = 0; i < n - 1; i++) {
    p[i] = i;
  }

  // cout << "p: "; DumpVector(p);

  int m;
  int64 k;
  cin >> m >> k;
  for (int i = 0; i < m; i++) {
    int op;
    cin >> op;
    op -= 2;
    swap(p[op], p[op + 1]);
  }

  // cout << "p: "; DumpVector(p);
  p = PermutationPower(p, k);
  
  int64 cur = xs[0];
  cout << cur << endl;
  for (int i = 0; i < n - 1; i++) {
    cur += ds[p[i]];
    cout << cur << endl;
  }
}
