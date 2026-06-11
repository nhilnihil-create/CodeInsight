#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;

  vector<int> D(K);
  for (int i = 0; i < K; i++)
  {
    cin >> D.at(i);
  }

  //計算量がそこまで大きくないので見つかるまで全探査
  int ans = N;
  while (true)
  {
    string strN = to_string(ans);
    bool includedHateNum = false;
    for (int i = 0; i < D.size(); i++)
    {
      if (count(strN.begin(), strN.end(), '0' + D.at(i)))
      {
        ans++;
        includedHateNum = true;
      }
    }
    if (!includedHateNum)
    {
      break;
    }
  }
  cout << ans << endl;
}