#include <bits/stdc++.h>
typedef int64_t ll;
using namespace std;
 
int main() {
  int n;
  cin >> n;
 
  ll a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
 
  ll op = 0LL;
  ll sum = 0LL;
 
  // 奇数番目が正
  for (int i = 0; i < n; i++) {
    sum += a[i];
 
    if (i % 2 == 0 && sum <= 0) {
      op += 1 - sum;
      sum = 1;
    }

    else if (i % 2 == 1 && sum >= 0) {
      op += sum + 1;
      sum = -1;
    }
  }
 
  ll op_m = op;//今回の結果をop_mに格納


  sum = 0LL;
  op = 0LL;

  // 偶数番目が正
  for (int i = 0; i < n; i++) {
    sum += a[i];
 
    if (i % 2 == 1 && sum <= 0) {
      op += 1 - sum;
      sum = 1;
    }
    
    else if (i % 2 == 0 && sum >= 0) {
      op += sum + 1;
      sum = -1;
    }
  }
 
  op = min(op, op_m);
  cout << op << endl;
  return 0;
}