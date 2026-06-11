#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, a, od = 0;
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> a;
    if (a % 2)
      od++;
  }
  cout << ((od % 2) ? "NO" : "YES") << endl;
}