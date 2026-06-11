#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n, k;
  cin >> n >> k;
  vector<pair<long long, long long>> V(n);
  for (int i = 0; i < n; i++)
  {
    cin >> V.at(i).first >> V.at(i).second;
  }

  sort(V.begin(), V.end());
  ll sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += V.at(i).second;
    if (sum >= k)
    {
      cout << V.at(i).first << endl;
      return 0;
    }
  }
}
