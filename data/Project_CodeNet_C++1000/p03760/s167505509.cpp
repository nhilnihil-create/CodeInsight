#include <iostream>
#include <string>

using namespace std;

int main()	{
  string a, b;
  cin >> a >> b;
  string c = a + b;
  int j = 0, k = 0;
  for (int i = 0; i < a.length() + b.length(); i++)	{
    if (i % 2 == 0)	{
      c[i] = a[j];
      j++;
    }
    else	{
      c[i] = b[k];
      k++;
    }
  }
  cout << c << endl;
  return 0;
}
