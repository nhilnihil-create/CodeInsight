#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1 << 18;
int n, dat[2*MAX_N - 1];

void init(int _n) {
  n = 1;
  while (n < _n) n *= 2;
  for (int i=0; i<2*n-1; i++) {
    dat[i] = INT_MAX;
  }
}

void update(int k, int a) {
  k += n - 1;
  dat[k] = a;
  while (k > 0) {
    k = (k - 1) / 2;
    dat[k] = min(dat[k*2 + 1], dat[k * 2 + 2]);
  }
}

int query(int a, int b, int k, int l, int r) {
  if (r <= a || b <= l) return INT_MAX;

  if (a <= l && r <= b) return dat[k];
  else {
    int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return min(vl, vr);
  }
}
int main() {

  int N;
  cin>>N;
  int a[N];
  for (int i=0; i<N; i++) cin>>a[i];
  init(N);
  for (int i=0; i<N; i++) {
    update(i, a[i]);
  }
  long long ans = 0;

  for (int i=0; i<N; i++) {
    int l_l = 0, r_l = i;
    while (r_l - l_l > 1) {
      int mid = (l_l + r_l) / 2;
      int v = query(mid, i+1, 0, 0, n);
      if (v < a[i]) {
        l_l = mid;
      } else {
        r_l = mid;
      }
    }
    int l;
    if (a[i] == query(l_l, i+1, 0, 0, n)) {
      l = l_l;
    } else {
      l = r_l;
    }
    int l_r = i, r_r = N-1;
    while (r_r - l_r > 1) {
      int mid = (l_r + r_r) / 2;
      int v = query(i, mid+1, 0, 0, n);
      if (v < a[i]) {
        r_r = mid;
      } else {
        l_r = mid;
      }
    }
    int r;
    if (a[i] == query(i, r_r+1, 0, 0, n)) {
      r = r_r;
    } else {
      r = l_r;
    }
    if (r == N) {
      --r;
    }
    ans += (long long)a[i] * (i - l + 1) * (r - i + 1);
  }
  cout<<ans<<endl;
}