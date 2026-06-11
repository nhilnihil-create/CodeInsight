#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S, T = "CODEFESTIVAL2016";
  cin >> S;
  int ans = 0;
  for (int i = 0; i < 16; i++)
  {
    if (S[i] != T[i])
      ans++;
  }
  cout << ans << endl;
}