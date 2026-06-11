#include <bits/stdc++.h>
using namespace std;

int main()
{
  int h, w;
  cin >> h >> w;
  vector<string> C;
  for (int i = 0; i < h; i++)
  {
    string s;
    cin >> s;
    C.push_back(s);
  }
  for (int i = 0; i < h; i++)
  {
    cout << C[i] << endl
         << C[i] << endl;
  }
}
