#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int N, K;
  cin >> N >> K;
  vector<int> nums;
  for (int i = 0; i < K; ++i)
  {
    int tmp;
    cin >> tmp;
    nums.push_back(tmp);
  }
  int i = 0;
  while (1)
  {
    int flag = 0;
    int tmp = N + i;
    string S = to_string(tmp);
    for (int j = 0; j < S.size(); ++j)
    {
      for (int k = 0; k < nums.size(); k++)
      {
        if (S[j]-'0' == nums[k])
        {
          flag = 1;
          break;
        }
      }
      if (flag)
        break;
    }
    if (flag==0)
    {
      cout << tmp << endl;
      break;
    }
    i++;
  }
}

int main()
{
  solve();
  return 0;
}
