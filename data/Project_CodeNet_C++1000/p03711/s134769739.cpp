#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  int x, y;
  cin >> x >> y;

  vector<int> a = {1, 3, 5, 7, 8, 10, 12};
  vector<int> b = {4, 6, 9, 11};
  vector<int> c = {2};


  rep(i,a.size()){
    if(a.at(i) == x){
      rep(j, a.size())
      {
        if (a.at(j) == y)
        {
          cout << "Yes";
          return 0;
        }
      }
    }
  }
  rep(i, b.size())
  {
    if (b.at(i) == x)
    {
      rep(j, b.size())
      {
        if (b.at(j) == y)
        {
          cout << "Yes";
          return 0;
        }
      }
    }
  }
  rep(i, c.size())
  {
    if (c.at(i) == x)
    {
      rep(j, c.size())
      {
        if (c.at(j) == y)
        {
          cout << "Yes";
          return 0;
        }
      }
    }
  }

  cout << "No";
}
