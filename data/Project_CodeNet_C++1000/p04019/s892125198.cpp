#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;
  map<char, int> mp = {{'N', 0}, {'W', 0}, {'S', 0}, {'E', 0}};
  for (int i = 0; i < (int)S.size(); i++)
  {
    mp[S[i]]++;
  }
  if (!abs(min(1, mp['N']) - min(1, mp['S'])) && !abs(min(1, mp['E']) - min(1, mp['W'])))
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}