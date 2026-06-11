#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;

set<ll> remain;
map<ll, int> orig;
ll arr [MAX_N];
ll pos [MAX_N];

vector<ll> ans;

ll L;
void try_del (ll cur) {
  auto it = remain.find(cur);
  if (it == remain.end()) return;
  if (it == remain.begin()) return;
  if (next(it) == remain.end()) return;

  ll nxt = *next(it);
  ll prv = *prev(it);
  if (nxt - prv < L) return;

  remain.erase(it);
  ans.push_back(cur);
  try_del(nxt);
  try_del(prv);
}

int main () {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n >> L;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i <= n; i++) {
    pos[i] = pos[i - 1] + arr[i];
    orig[pos[i]] = i;
  }
  
  for (int i = 0; i <= n; i++) {
    remain.insert(pos[i]);
  }

  for (int i = 1; i < n; i++) {
    try_del(pos[i]);
  }

  if ((int) remain.size() != 2) {
    cout << "Impossible" << endl;
    exit(0);
  }

  cout << "Possible" << endl;
  reverse(ans.begin(), ans.end());
  for (ll x : ans) {
    cout << orig[x] << '\n';
  }
}
