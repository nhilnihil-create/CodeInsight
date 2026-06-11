#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define INF 1000000000000
typedef long long ll;

int main()
{
  ll n, m, min, minNum;
  pair<ll, ll> minP;
  cin >> n >> m;

  vector<pair<ll, ll>> stu(n);
  vector<pair<ll, ll>> p(m);
  REP(i, n)
  {
    cin >> stu[i].first >> stu[i].second;
  }
  REP(i, m)
  {
    cin >> p[i].first >> p[i].second;
  }

  REP(i, n)
  {
    min = abs(stu[i].first - p[0].first) + abs(stu[i].second - p[0].second);
    minP.first = p[0].first;
    minP.second = p[0].second;
    minNum = 1;
    REP(j, m)
    {

      if (min > (abs(stu[i].first - p[j].first) + abs(stu[i].second - p[j].second)))
      {
        min = abs(stu[i].first - p[j].first) + abs(stu[i].second - p[j].second);
        minP.first = p[j].first;
        minP.second = p[j].second;
        minNum = j + 1;
      }
      else if (min == (abs(stu[i].first - p[j].first) + abs(stu[i].second - p[j].second)))
      {
        if (p[j].first < minP.first || p[j].second < minP.second)
        {
          minP.first = p[j].first;
          minP.second = p[j].second;
          min = abs(stu[i].first - p[j].first) + abs(stu[i].second - p[j].second);
          minNum = j + 1;
        }
      }
    }
    cout << minNum << endl;
  }
}