#include <iostream>
#include <vector>

using namespace std;

int main()	{
  int n, m;
  cin >> n;
  int t[n];
  for (int i = 0; i < n; i++)	{
    cin >> t[i];
  }
  cin >> m;
  vector<pair<int, int>> power;
  int tmp1, tmp2;
  for (int i = 0; i < m; i++)	{
    cin >> tmp1 >> tmp2;
    power.push_back(make_pair(tmp1 - 1, tmp2));
  }
  long long times[m];
  for (int i = 0; i < m; i++)	{
    times[i] = 0;
    for (int j = 0; j < n; j++)	{
      tmp1 = t[j];
      if (j == power[i].first)	{
        t[j] = power[i].second;
      }
      times[i] += t[j];
      t[j] = tmp1;
    }
  }
  for (int i = 0; i < m; i++)	
    cout << times[i] << endl;
  return 0;
}