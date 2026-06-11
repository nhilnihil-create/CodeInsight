#include<iostream>

using namespace std;

const static int MAX_N = 100000;
int n;
int m;

long long x[MAX_N];
long long y[MAX_N];

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> y[i];
  }

  long long sum_x = 0;
  for (int k = 1; k <= n; k++) {
    sum_x += ((long long)(k - 1) * x[k - 1]) - ((long long)(n - k) * x[k - 1]);
  }

  long long sum_y = 0;
  for (int k = 1; k <= m; k++) {
    sum_y += ((long long)(k - 1) * y[k - 1]) - ((long long)(m - k) * y[k - 1]);
  }

  long long ans = (sum_x % 1000000007) * (sum_y % 1000000007);
  ans = ans % 1000000007;

  cout << ans << endl;
  return 0;
}
