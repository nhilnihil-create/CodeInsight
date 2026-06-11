
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;

  const int nmmax = 50;
  int a[nmmax], b[nmmax];

  for (int i = 0; i < M; ++i)
  {
    cin >> a[i] >> b[i];
  }

  int road[nmmax];
  for (int i = 0; i < N; ++i)
  {
    road[i] = 0;
  }

  for (int i = 0; i < M; ++i)
  {
    road[a[i] - 1] += 1;
    road[b[i] - 1] += 1;
  }

  for (int i = 0; i < N; ++i)
  {
    cout << road[i] << endl;
  }
  return 0;
}
