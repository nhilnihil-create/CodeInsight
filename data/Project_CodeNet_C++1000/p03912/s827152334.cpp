#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

int main() {
  int N, M; cin >> N >> M;
  map<int, int> X; rep(i,N) { int tmp; cin >> tmp; X[tmp]++; }
  int odd[M] = {}, p[M] = {};
  for (auto x: X) {
    int mo = x.first%M;
    if (x.second%2==1) odd[mo]++;
    p[mo] += x.second/2;
  }
  // rep(i,M) cout << i << ":" << odd[i] << "&" << p[i] << endl;
  ll result = 0;
  rep(i,M/2+1) {
    if (i==0||i*2==M) { result += odd[i]/2 + p[i]; continue; }
    if (odd[i]<odd[M-i]) {
      result += odd[i];
      result += p[M-i];
      int left = odd[M-i]-odd[i];
      result += (left>=p[i]*2) ? p[i]*2 : (left/2+p[i]);
    }
    else {
      result += odd[M-i];
      result += p[i];
      int left = odd[i]-odd[M-i];
      result += (left>=p[M-i]*2) ? p[M-i]*2 : (left/2+p[M-i]);
    }
  }
  cout << result << endl;
  return 0;
}