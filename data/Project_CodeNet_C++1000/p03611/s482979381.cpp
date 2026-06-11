#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using vi  = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

int main() {
  int N;
  cin >> N;
  map<int, int> map;
  int a;
  rep(i,N) {
    cin >> a;
    map[a] += 1;
  }
  int ans, curr;
  ans = 0;
  rep(i, 100001) {
    curr=map[i-1]+map[i]+map[i+1];
    ans = curr > ans ? curr : ans;
  }

  cout << ans << endl;
}
