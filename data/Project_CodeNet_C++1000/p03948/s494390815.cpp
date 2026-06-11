#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int a[100010];
int mx[100010];

int main(){
  int n, t;
  cin >> n >> t;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  mx[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] > mx[i + 1]) {
      mx[i] = a[i];
    } else {
      mx[i] = mx[i + 1];
    }
  }
  int dif = 0;
  int cnt = 0;
  for (int i = 0; i < n - 1; i++) {
    if (mx[i + 1] - a[i] > 0) {
      if (mx[i + 1] - a[i] > dif) {
        dif = mx[i + 1] - a[i];
        cnt = 1;
      } else if (mx[i + 1] - a[i] == dif) {
        cnt++;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
