#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, M, a, b;
  cin >> N >> M;
  vector<int64_t> A(N + 1, 0);
  for (int i = 0; i < M; i++)
  {
    cin >> a >> b;
    A.at(a)++;
    A.at(b)++;
  }
  for (auto n : A)
  {
    if (n % 2)
    {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}