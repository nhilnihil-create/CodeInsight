#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N)
  {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  vector<pair<int, int>> B;
  B.push_back(make_pair(A[0], 1));
  rep(i, N - 1)
  {
    if (B.back().first == A[i + 1])
      B.back().second++;
    else
      B.push_back(make_pair(A[i + 1], 1));
  }

  int ans = N;
  int head = 0;
  int tail = B.size() - 1;
  for (; head <= tail;)
  {
    if (B[head].second < 2)
    {
      head++;
      continue;
    }

    for (; tail > head; tail--)
    {
      if (B[tail].second < 2)
        continue;

      B[head].second--;
      B[tail].second--;
      ans -= 2;
      break;
    }

    if (head == tail)
    {
      ans -= (B[head].second / 2) * 2;
      B[head].second = 1;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}