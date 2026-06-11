#include <bits/stdc++.h>
using namespace std;
const int64_t MAXN = 100010;
int64_t N, A, B;
vector<int64_t> H(MAXN);

bool ok(int64_t n)
{
  int64_t a = 0;
  for (int i = 0; i < N; i++)
  {
    if (B * n >= H[i])
      continue;
    a += ((H[i] - B * n) + (A - B - 1)) / (A - B);
  }
  return a <= n;
}

int main()
{
  int64_t mx = 0;
  cin >> N >> A >> B;
  for (int i = 0; i < N; i++)
  {
    cin >> H.at(i);
    mx = max(H.at(i), mx);
  }
  int64_t l = -1, r = (mx + (B - 1)) / B;
  while (r - l > 1)
  {
    int64_t m = (r + l) / 2;
    if (ok(m))
      r = m;
    else
      l = m;
  }
  cout << r << endl;
}
