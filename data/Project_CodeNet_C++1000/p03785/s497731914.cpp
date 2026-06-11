#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, c, k; cin >> n >> c >> k;
  priority_queue<int, vector<int>, greater<int>> arrival;
  priority_queue<int, vector<int>, greater<int>> limit;
  int ans = 0;
  rep(i,n) {
    int t; cin >> t;
    arrival.push(t);
    limit.push(t+k);
  }
  int now = 0;
  queue<int> train;
  while(!arrival.empty()) {
    now++;
    while (now == arrival.top() && !arrival.empty()) {
      train.push(arrival.top());
      arrival.pop();
      if ((int)train.size() == c) {
        ans++;
        while(!train.empty()) {
          train.pop();
          limit.pop();
        }
      }
    }
    if (!train.empty()) {
      if (now == limit.top() || arrival.empty()) {
        ans++;
        while(!train.empty()) {
          train.pop();
          limit.pop();
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}