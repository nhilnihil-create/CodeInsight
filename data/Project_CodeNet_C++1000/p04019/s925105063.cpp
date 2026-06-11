#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S; // NとS,WとE
  int64_t D[4] = {0, 0, 0, 0};
  for (int i = 0; i < S.size(); i++)
  {
    if (S.at(i) == 'N')
      D[0]++;
    else if (S.at(i) == 'E')
      D[1]++;
    else if (S.at(i) == 'S')
      D[2]++;
    else if (S.at(i) == 'W')
      D[3]++;
  }
  if (D[0] && !D[2] || !D[0] && D[2] || D[1] && !D[3] || !D[1] && D[3])
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
}