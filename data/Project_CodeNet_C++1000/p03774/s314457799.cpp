#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  vector<int64_t> A(N), B(N), C(M), D(M);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i] >> B[i];
  }
  for (int i = 0; i < M; i++)
  {
    cin >> C[i] >> D[i];
  }
  for (int i = 0; i < N; i++)
  {
    int64_t mind = (1LL << 62), minj = 0;
    for (int j = 0; j < M; j++)
    {
      int64_t d = abs(A.at(i) - C.at(j)) + abs(B.at(i) - D.at(j));
      if (d < mind)
      {
        mind = d;
        minj = j;
      }
    }
    cout << minj + 1 << endl;
  }
}
