#include <bits/stdc++.h>
using namespace std;
bool checked[110][110];

int main()
{
  int H, W;
  cin >> H >> W;
  char c;
  vector<int> A(26, 0);
  for (int i = 0; i < H * W; i++)
  {
    cin >> c;
    A.at((int)(c - 'a'))++;
  }
  int cnt = 0;
  vector<int> v(5, 0);
  if (H % 2 && W % 2)
  {
    v.at(1)++;
    cnt++;
  }
  if (H % 2)
  {
    for (int i = 0; i < W / 2; i++)
    {
      v.at(2)++;
      cnt += 2;
    }
  }
  if (W % 2)
  {
    for (int i = 0; i < H / 2; i++)
    {
      v.at(2)++;
      cnt += 2;
    }
  }
  for (int i = 0; i < (H * W - cnt) / 4; i++)
  {
    v.at(4)++;
  }
  for (int i = 0; i < (int)(A.size()); i++)
  {
    if (A.at(i) == 0)
      continue;
    if (A.at(i) % 2 == 1)
    {
      if (v.at(1) == 0)
      {
        cout << "No" << endl;
        return 0;
      }
      else
      {
        A.at(i)--;
        v.at(1)--;
      }
    }
    while (A.at(i) >= 4 && v[4] >= 1)
    {
      A.at(i) -= 4;
      v[4]--;
    }
    while (A.at(i) >= 2 && v[2] >= 1)
    {
      A.at(i) -= 2;
      v[2]--;
    }
    if (A.at(i) > 0)
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
