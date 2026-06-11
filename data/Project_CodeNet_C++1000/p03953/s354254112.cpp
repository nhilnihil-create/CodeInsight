#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5;
int n;
ll m, k;
ll a[N];
ll d[N];
int o[N];

vector<int> mult(vector<int> &a, vector<int> &b){ 
  auto res = a;
  for(int i = 0; i < n; i++) {
    res[i] = b[a[i]];
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if(i) d[i] = a[i] - a[i - 1];
  }
  cin >> m >> k;
  vector<int> ord(n);
  iota(begin(ord), end(ord), 0);
  for(int i = 0; i < m; i++) {
    cin >> o[i], o[i]--;
    swap(ord[o[i]], ord[o[i] + 1]);
  }
  vector<int> b(n);
  for(int i = 0; i < n; i++) {
    b[ord[i]] = i;
  }
  vector<int> ans(n);
  iota(begin(ans), end(ans), 0);
  while(k) {
    if(k & 1) ans = mult(ans, b);
    b = mult(b, b);
    k >>= 1;
  }
  vector<ll> x(n);
  for(int i = 0; i < n; i++) {
    x[ans[i]] = d[i];
  }
  for(int i = 1; i < n; i++) a[i] = a[i - 1] + x[i];
  for(int i = 0 ;i < n; i++) cout << a[i] << endl;
}

