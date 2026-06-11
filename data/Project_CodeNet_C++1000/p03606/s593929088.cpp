#include <iostream>

using namespace std;

int main()	{
  int n;
  cin >> n;
  long long total = 0;
  int a, b;
  for (int i = 0; i < n; i++)	{
    cin >> a >> b;
    total += b - a + 1;
  }
  cout << total << endl;
  return 0;
}