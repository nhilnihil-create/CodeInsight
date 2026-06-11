#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, answer = INT_MAX, x;
  cin >> N;
  int a[N];
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (int y = *min_element(a,a+N), n = *max_element(a,a+N); y <= n; y++) {
    x = 0;
    for (int i = 0; i < N; i++) {
      x += (a[i]-y)*(a[i]-y);
    }
    answer = min(answer,x);
  }
  cout << answer;
}