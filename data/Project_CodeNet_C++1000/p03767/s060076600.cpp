#include <bits/stdc++.h>
using namespace std;
int n;
long long a[300010];
int main() {
  cin >> n;
  for (int i = 0; i < n*3; i++) cin >> a[i];
  sort(a,a+n*3);
  reverse(a,a+n*3);
  long long S = 0;
  for (int i = 0; i < n*2; i+=2) {
    S += a[i+1];
  }
  cout << S << endl;
}

/*　【提出前に確認すること】
・コンパイルできるか
・テストケース試したか
・オーバーフローあるか
*/