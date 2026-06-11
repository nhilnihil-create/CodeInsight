#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<int> a(3 * N);
  for (int i = 0; i < 3 * N; i++) {
    cin >> a[i];
  }

  ll psum = 0, ssum = 0;
  priority_queue<int, vector<int>, greater<int> > pre;
  priority_queue<int> suf;

  for (int i = 0; i < N; i++) {
    psum += a[i];
    pre.push(a[i]);
    ssum += a[3 * N - 1 -i];
    suf.push(a[3 * N - 1 - i]);
  }

  vector<ll> vpsum, vssum;
  vpsum.push_back(psum);
  vssum.push_back(ssum);

  for (int i = N; i < 2 * N; i++) {
    int pt = a[i];
    pre.push(pt);
    psum += pt;
    psum -= pre.top();
    pre.pop();
    vpsum.push_back(psum);
  }

  for (int i = 2 * N - 1; i >= N; i--) {
    int rt = a[i];
    suf.push(rt);
    ssum += rt;
    ssum -= suf.top();
    suf.pop();
    vssum.push_back(ssum);
  }

  reverse(vssum.begin(), vssum.end());

  ll res = (ll) -1e15;
  for (int i = 0; i <= N; i++) {
    res = max(res, vpsum[i] - vssum[i]);
  }
  cout << res << endl;
  return 0;
}