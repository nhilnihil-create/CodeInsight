
#include <bits/stdc++.h>

#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX_N = 300000, MAX_M = 100000;
int N, M;
int l[MAX_N], r[MAX_N];

const int DATA_SIZE = 1 << 18;
int n;
ll data1[2*DATA_SIZE-1], data2[2*DATA_SIZE-1]; // data1は区間全てに足される数、data2は区間の一部に足される数の総和。

void init(int n_) {
  n = 1;
  while (n <= n_) n*=2;
  return;
}

// range = [a,b), add = x, node number = k, node range = [l,r)
void update(int a, int b, ll x, int k, int l, int r) {
  if (r <= a || b <= l) return;
  if (a <= l && r <= b) {
    data1[k] += x;
  } else {
    data2[k] += (min(b,r)-max(a,l)) * x;

    int chl = 2*k+1, chr = 2*k+2;
    update(a, b, x, chl, l, (l+r)/2);
    update(a, b, x, chr, (l+r)/2, r);
  }
  return;
}

// range = [a,b), node number = k, node range = [l,r)
ll sum(int a, int b, int k, int l, int r) {
  if (r <= a || b <= l) return 0;
  if (a <= l && r <= b) {
    return data1[k]*(r-l) + data2[k];
  } else {
    ll res = (min(b,r)-max(a,l)) * data1[k];

    int chl = 2*k+1, chr = 2*k+2;
    res += sum(a, b, chl, l, (l+r)/2);
    res += sum(a, b, chr, (l+r)/2, r);
    
    return res;
  }
  return 0;
}

int ans[MAX_M+1];

int main() {
  cin >> N >> M;
  rep(i,N) cin >> l[i] >> r[i];

  vector<pii> v(N);
  rep(i,N) {
    v[i].fi = r[i]-l[i]+1; v[i].sc = i;
  }
  sort(all(v));

  init(M+1);

  for (int d = 1; d <= M; ++d) {
    ans[d] =  v.end() - lower_bound(all(v), pii(d, -1));
    for (vector<pii>::iterator ite = lower_bound(all(v), pii(d-1, -1)); ite != v.end() && ite->fi < d; ++ite) { 
      update(l[ite->sc], r[ite->sc]+1, 1, 0, 0, n); 
    }

    for (int k = 1; k*d <= M; ++k) {
      ans[d] += sum(k*d, k*d+1, 0, 0, n);
    }
  }

  for (int d = 1; d <= M; ++d) printf("%d\n", ans[d]);

  return 0;
}
