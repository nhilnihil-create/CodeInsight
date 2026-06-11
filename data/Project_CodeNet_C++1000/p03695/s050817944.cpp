#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  vector<int> A(n);
  map<int, int> cnt;
  rep(i,n) {
    cin >> A[i];
    if (A[i] >= 3200) {
      cnt[3200]++;
    } else {
      cnt[A[i]/400]++;
    }
  }
  int minv,maxv;
  minv = cnt.size();
  maxv = minv;
  if (cnt.count(3200)) {
    if (minv != 1) {
      minv--;
    }
    maxv--;
    maxv += cnt[3200];
  }
  cout << minv << " ";
  cout << maxv << endl;
  return 0;
}