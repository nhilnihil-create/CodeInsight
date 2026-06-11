#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn], sign[maxn];
long long mem[maxn][3];
int n;

long long dp(int cur, int nest) {
  if(cur == n) {
    return 0;
  }
  if(mem[cur][nest] != -1) return mem[cur][nest];
  int val = (nest & 1) ? -1 : 1;
  val *= sign[cur] * a[cur]; 
  long long ans = dp(cur + 1, nest) + val;
  if(nest > 0) ans = max(ans, dp(cur + 1, nest - 1) + val);
  if(sign[cur] == -1 && nest < 2) {
    ans = max(ans, dp(cur + 1, nest + 1) + val);
  }
  return mem[cur][nest] = ans;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  sign[0] = 1;
  cin >> a[0];
  for(int i = 1; i < n; i++) {
    char c;
    cin >> c >> a[i];
    sign[i] = (c == '-') ? -1 : 1;
  }
  memset(mem, -1, sizeof mem);
  cout << dp(0, 0) << endl;
  return 0;
}
