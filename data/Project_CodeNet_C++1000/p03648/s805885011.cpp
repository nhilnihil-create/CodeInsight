#include <bits/stdc++.h>
using namespace std;

long long upper = 10e16 + 1000;

int main()
{
  long long K;
  cin >> K;
  int n = 50;
  vector<long long> res(50);
  for (int i = 0; i < 50; ++ i) {
    res[i] = i;
  }
  for (int i = 0; i < 50; ++ i) {
    res[i] += K / n;
  }
  for (int i = 0; i < K % n; ++ i) {
    res[i] += n;
    for (int j = 0; j < n; ++ j) {
      if (i != j) {
        res[j] --;
      }
    }
  }
  cout << 50 << endl;
  for (int i = 0; i < 50; ++ i) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}
