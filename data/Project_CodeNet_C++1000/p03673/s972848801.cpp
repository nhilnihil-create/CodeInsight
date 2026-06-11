#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  long long MAX = 200000;
  cin >> n;
  vector<int> a(n);
  vector<int> b;
  vector<int> c;

  for (int i = 0; i < n; i++)
  {
    cin >> a.at(i);
  }

  for (int i = 0; i < n; i++)
  {
    if (i % 2 == 0)
    {
      b.insert(b.begin(), a.at(i));
    }
    else
    {
      b.push_back(a.at(i));
    }
  }
  if (b.size() > 1 && b.size() % 2 == 0)
  {
    reverse(b.begin(), b.end());
  }

  for (int i = 0; i < n; i++)
  {
    if (i)
    {
      cout << " ";
    }
    cout << b.at(i);
  }
  cout << endl;
}
