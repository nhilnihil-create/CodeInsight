#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;
typedef vector<vector<ll>> matrix;

void die() {
  cout << "0\n";
  exit(0);
}

map<int, int> must;

void force(int x, int y) {
  if(must.count(x) && must[x] != y) die();
  must[x] = y;
}

void solve() {
  int n;
  vector<int> ltor, rtol;
  cin >> n;
  ltor.resize(n);
  rtol.resize(n);
  for(int i = 0; i < n; i++) cin >> ltor[i];
  for(int i = 0; i < n; i++) cin >> rtol[i];
  force(0, ltor[0]);
  for(int i = 1; i < n; i++) {
    if(ltor[i] != ltor[i-1]) force(i, ltor[i]);
  }
  force(n-1, rtol[n-1]);
  for(int i = n-2; i >= 0; i--) {
    if(rtol[i] != rtol[i+1]) force(i, rtol[i]);
  }
  {
    int curr = 0;
    for(int i = 0; i < n; i++) {
      if(must.count(i)) curr = max(curr, must[i]);
      if(curr != ltor[i]) die();
    }
  }
  {
    int curr = 0;
    for(int i = n-1; i >= 0; i--) {
      if(must.count(i)) curr = max(curr, must[i]);
      if(curr != rtol[i]) die();
    }
  }

  ll ret = 1;
  for(int i = 0; i < n; i++) {
    if(must.count(i)) continue;
    ret *= min(ltor[i], rtol[i]);
    ret %= 1000000007;
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
  solve();
}
