#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;
using VVB = vector<VB>;

int main(int argc, char const *argv[]) {
  int num, k;
  cin >> num >> k;
  VI a(num);
  for (int i = 0; i < num; i ++) {
    cin >> a[i];
  }

  VVB dp1(num + 1, VB(k, false));
  dp1[0][0] = true;
  for(int i = 0; i < num; i ++) {
    for(int j = 0; j < k; j ++) {
      dp1[i + 1][j] = dp1[i][j];
    }
    for(int j = 0; j + a[i] < k; j ++) {
      dp1[i + 1][j + a[i]] = dp1[i + 1][j + a[i]] || dp1[i][j];
    }
  }
  VVI max1(num + 1, VI(k, 0));
  for(int i = 0; i <= num; i ++) {
    for(int j = 1; j < k; j ++) {
      max1[i][j] = max1[i][j - 1];
      if(dp1[i][j]) max1[i][j] = j;
    }
  }
  VVB dp2(num + 1, VB(k, false));
  dp2[num][0] = true;
  for(int i = num; i > 0; i --) {
    for(int j = 0; j < k; j ++) {
      dp2[i - 1][j] = dp2[i][j];
    }
    for(int j = 0; j + a[i - 1] < k; j ++) {
      dp2[i - 1][j + a[i - 1]] = dp2[i - 1][j + a[i - 1]] || dp2[i][j];
    }
  }
  VVI max2(num + 1, VI(k, 0));
  for(int i = 0; i <= num; i ++) {
    for(int j = 1; j < k; j ++) {
      max2[i][j] = max2[i][j - 1];
      if(dp2[i][j]) max2[i][j] = j;
    }
  }
  ll ans = 0;
  for(int i = 0; i < num; i ++) {
    bool b = a[i] >= k;
    for(int j = 0; j < k; j ++) {
      b |= max1[i][j] + max2[i + 1][k - j - 1] >= k - a[i];
    }
    if(!b) ans ++;
  }
  cout << ans << endl;
  return 0;
}
