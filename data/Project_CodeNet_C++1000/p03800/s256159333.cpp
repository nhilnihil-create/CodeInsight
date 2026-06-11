#include <bits/stdc++.h>
#define INF 1000000000000000001
#define ll long long
#define pll pair<ll, ll>
using namespace std;

//ture == sheep
vector<bool> next(bool fir, bool sec, string& s)
{
  vector<bool> res = {fir, sec};

  ll N = s.size();
  for (ll i = 0; i < N; ++i)
  {
    if (sec)
    {
      if (s[i] == 'o')
      {
        res.push_back(fir);
      }
      else
      {
        res.push_back(!fir);
      }
    }
    else
    {
      if (s[i] == 'o')
      {
        res.push_back(!fir);
      }
      else
      {
        res.push_back(fir);
      }
    }
    fir = sec;
    sec = *(res.end() - 1);
  }
  return res;
}


int main()
{
  ll N;
  cin >> N;
  string s;
  cin >> s;
  vector<bool> temp = next(true, true, s);
  for (ll i = 0; i < 2; ++i)
  {
    for (ll j = 0; j < 2; ++j)
    {
      temp = next(i, j, s);
      if (temp.at(0) == *(temp.end() - 2) && temp.at(1) == *(temp.end() - 1))
      {
        for (ll i = 1; i < N + 1; ++i)
        {
          if (temp.at(i))
          {
            cout << "S";
          }
          else
          {
            cout << "W";
          }
        }
        cout << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
}
