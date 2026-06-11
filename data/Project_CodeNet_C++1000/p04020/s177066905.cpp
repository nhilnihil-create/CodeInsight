#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<long long> a(N);
  for (int i = 0; i < N; ++i)
    cin >> a[i];
  long long res = 0, cur_sum = 0;
  for (int i = 0; i < N;)
  {
    int j = i;
    while (j < N && a[j])
      cur_sum += a[j++];
    res += cur_sum / 2;
    cur_sum = 0;
    i = j + 1;
  }
  cout << res << endl;
}