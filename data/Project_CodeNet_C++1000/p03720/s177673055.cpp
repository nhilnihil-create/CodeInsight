#include <iostream>
#include <unordered_map>

using namespace std;

int main()	{
  int n, m;
  cin >> n >> m;
  unordered_map<int, int> cities;
  int a, b;
  for (int i = 0; i < m; i++)	{
    cin >> a >> b;
    cities[a]++;
    cities[b]++;
  }
  for (int i = 1; i <= n; i++)	{
    cout << cities[i] << endl;
  }
  return 0;
}