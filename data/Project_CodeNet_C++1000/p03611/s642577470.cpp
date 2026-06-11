#include <iostream>
#include <unordered_map>

using namespace std;

int main()	{
  int n;
  cin >> n;
  int a[n] = {0};
  unordered_map<int, int> count;
  for (int i = 0; i < n; i++)	{
    cin >> a[i];
    count[a[i]]++;
    count[a[i] - 1]++;
    count[a[i] + 1]++;
  }
  int max = -2;
  for (auto it = count.begin(); it != count.end(); it++)	{
    if ((*it).second > max)
      max = (*it).second;
  }
  cout << max << endl;
  return 0;
}