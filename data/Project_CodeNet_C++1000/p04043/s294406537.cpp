#include <bits/stdc++.h>
using namespace std;

int main()
{
  string tanka;
  getline(cin, tanka);

  if (tanka == "5 5 7" || tanka == "5 7 5" || tanka == "7 5 5")
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
}