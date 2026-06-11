#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;
int main()
{
  ll Q, H, S, D, N;
  cin >> Q >> H >> S >> D >> N;
  H = min(H, 2 * Q);
  S = min(S, 2 * H);
  if (2 * S <= D)
  {
    cout << N * S << endl;
  }
  else
  {
    cout << (N / 2) * D + (N % 2) * S << endl;
  }
  return 0;
}