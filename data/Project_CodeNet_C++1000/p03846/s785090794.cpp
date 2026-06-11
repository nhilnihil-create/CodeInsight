#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

long long pow(int base, int expo)	{
  if (base == 0) return 0;
  if (expo == 0) return 1;
  int result = 1;
  for (int i = 0; i < expo; i++)	{
    result *= base;
    result %= 1000000007;
  }
  return result % 1000000007;
}

int main()	{
  int n;
  cin >> n;
  int input[n];
  unordered_map<int, int> freq;
  for (int i = 0; i < n; i++)	{
    cin >> input[i];
    freq[input[i]]++;
  }
  for (auto it : freq)	{
    if (it.first == 0 && it.second > 1)	{
      cout << 0 << endl;
      return 0;
    }
	else if (it.first != 0 && it.second != 2)	{
      cout << 0 << endl;
      return 0;
    }
  }
  cout << pow(2, (n / 2)) << endl;
  return 0;
}