#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  int a[N];
  for (int i = 0; i < N; i++) cin >> a[i];
  sort(a,a+N);
  if (a[N-1] - a[0] >= 2) {
    cout << "No" << endl;
  } else if (a[N-1] - a[0] == 1) {
    int cnt = 0;
    int num = a[N-1];
    for (int i = 0; i < N; i++) {
      if (a[i] == a[0]) {
        cnt++;
      }
    }
    int c = num - 1;
    if (N == num) {
      c = num;
    }
    if (max(num*2 - N,0) <= cnt && cnt <= c) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else {
    if (2 * a[0] <= N || a[0] == N - 1) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}