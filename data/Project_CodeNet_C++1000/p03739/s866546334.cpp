#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, negfst = 0, posfst = 0, plus = 0;
  cin >> N;
  vector<int64_t> A(N), S(N + 1, 0);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
    S.at(i + 1) = S.at(i) + A.at(i);
  }
  // 1番目が正の場合
  for (int i = 1; i <= N; i++)
  {
    if (i % 2 == 1 && S.at(i) + plus <= 0) // 奇数番目が負の場合
    {
      posfst += abs(S.at(i) + plus) + 1; // 足して+1にする
      plus += abs(S.at(i) + plus) + 1;   // 足した分を加味する
    }
    else if (i % 2 == 0 && S.at(i) + plus >= 0)
    {
      posfst += abs(S.at(i) + plus) + 1; // 引いて-1にする
      plus -= abs(S.at(i) + plus) + 1;   // 引いた分を加味する
    }
  }
  // 1番目が負の場合
  plus = 0;
  for (int i = 1; i <= N; i++)
  {
    if (i % 2 == 1 && S.at(i) + plus >= 0) // 奇数番目が正の場合
    {
      negfst += abs(S.at(i) + plus) + 1;
      plus -= abs(S.at(i) + plus) + 1;
    }
    else if (i % 2 == 0 && S.at(i) + plus <= 0)
    {
      negfst += abs(S.at(i) + plus) + 1;
      plus += abs(S.at(i) + plus) + 1;
    }
  }
  cout << (posfst <= negfst ? posfst : negfst) << endl;
}