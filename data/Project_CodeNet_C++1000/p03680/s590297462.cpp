#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n+1);
  rep(i, n) {
    cin >> a[i+1];
//    cout << a[i+1] << endl;
  }
  vector<bool> memo(n+1);
  
  memo[1]=true;
  int now = 1;
  int ans = 0;
  do {
    int next = a[now];
//    cout << next << " " << memo[next] << endl;
    if(memo[next]) {
      cout << -1 << endl;
      return 0;
    }
    memo[next] = true;
    now = next;
    ++ans;
  } while(now != 2);
  
  cout << ans << endl;
  
  return 0;
}
