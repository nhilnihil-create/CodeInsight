#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve() {
  ll n;
  cin >> n;
  vector<ll> ret;
  ret.resize(50);
  for(int i = 0; i < 50; i++) ret[i] = 49;
  ll fullInc = n/50;
  n %= 50;
  for(int i = 0; i < 50; i++) ret[i] += fullInc;
  int f = 0;
  while(n--) {
    ret[f] += 50;
    for(int i = 0; i < 50; i++) if(i != f) ret[i]--;
    f++;
  }
  cout << "50\n";
  for(int i = 0; i < 50; i++) {
    cout << ret[i];
    if(i == 49) cout << endl;
    else cout << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}
