#include <bits/stdc++.h>

using namespace std;

long long Sum(long long n)
{
  return n * (n + 1) / 2;
}

void hawawa()
{
  int n;
  cin >> n;
  int mi = 1, ma = n;
  while (mi < ma) {
    int mid = (mi + ma) / 2;
    if (n <= Sum(mid)) {
      ma = mid;
    } else {
      mi = mid + 1;
    }
  }
  int score = Sum(mi);
  for (int i = 1; i <= mi; i++) {
    if (score - n == i) {
      continue;
    }
    cout << i << "\n";
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  hawawa();
  return 0;
}