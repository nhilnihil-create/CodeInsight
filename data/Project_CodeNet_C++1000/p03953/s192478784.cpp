#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> perm;

perm mul (perm p, perm q) {
  int n = p.size();
  perm ans (n);
  for (int i = 0; i < n; i++) {
    ans[i] = p[q[i]];
  }
  return ans;
}

perm id (int n) {
  perm ans (n);
  for (int i = 0; i < n; i++) {
    ans[i] = i;
  }
  return ans;
}

perm exp (perm p, ll k) {
  if (k == 0) {
    return id(p.size());
  } else if (k % 2 == 0) {
    perm half = exp(p, k / 2);
    return mul(half, half);
  } else {
    return mul(p, exp(p, k - 1));
  }
}

const int MAX_N = 1e5 + 5;

ll x [MAX_N];
int arr [MAX_N];

ll ids [MAX_N];
ll fds [MAX_N];

ll ans [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }

  for (int i = 0; i < n - 1; i++) {
    ids[i] = x[i + 1] - x[i];
  }
  
  int m;
  ll k;
  cin >> m >> k;

  for (int i = 0; i < m; i++) {
    cin >> arr[i];
    arr[i]--;
  }

  perm p = id(n - 1);
  for (int i = m - 1; i >= 0; i--) {
    int u = arr[i];
    int v = u - 1;
    swap(p[u], p[v]);
  }

  p = exp(p, k);
  for (int i = 0; i < n - 1; i++) {
    fds[p[i]] = ids[i];
  }

  ans[0] = x[0];
  for (int i = 1; i < n; i++) {
    ans[i] = ans[i - 1] + fds[i - 1];
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << ".0\n";
  }
}
