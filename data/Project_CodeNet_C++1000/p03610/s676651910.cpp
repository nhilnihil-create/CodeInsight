#include <iostream>
#include <string>

using namespace std;

int main()	{
  string a;
  cin >> a;
  string b;
  int n = a.length();
  for (int i = 0; i < n; i++)	{
    if (i % 2 == 0)	{
      b.push_back(a[i]);
    }
  }
  cout << b << endl;
  return 0;
}