#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t K, T, cnt = 0;
  cin >> K >> T;
  vector<int64_t> A(T);
  for (int64_t i = 0; i < T; i++)
    cin >> A.at(i);
  int64_t previ = -1, maxt = 0, maxi;
  for (int k = 0; k < K; k++)
  {
    for (int64_t i = 0; i < T; i++)
    {
      if (i == previ)
        continue;
      if (A.at(i) > maxt)
      {
        maxt = A.at(i);
        maxi = i;
      }
    }
    A.at(maxi)--;
    if (previ == maxi)
      cnt++;
    maxt = 0;
    previ = maxi;
  }
  cout << cnt << endl;
}