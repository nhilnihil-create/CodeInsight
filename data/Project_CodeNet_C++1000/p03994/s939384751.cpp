#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  int64_t K;
  cin >> S >> K;
  for (int i = 0; i < S.size(); i++)
  {
    int64_t sint = S[i] - 'a';
    int64_t toA = 26 - sint;
    if (toA != 26 && K >= toA)
    {
      K -= toA;
      S[i] = 'a';
    }
  }
  if (K > 0)
  {
    int64_t sint = S[S.size() - 1] - 'a';
    int64_t after = (sint + K) % 26;
    S[S.size() - 1] = 'a' + after;
  }
  cout << S << endl;
}
