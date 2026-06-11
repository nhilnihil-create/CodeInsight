#include <iostream>

using namespace std;

int main()
{
  long long a,b;
  cin >> a >> b;
  long long i = a+1;
  long long ans = a;
  if (a > 0 && b > 0)
    cout << "Positive" << endl;
  if (a < 0 && b < 0)
  {
    if ((b - a + 1) % 2 ==0)
      cout << "Positive" << endl;
    else
      cout << " Negative" << endl;
  }
  if (a <= 0 && b >= 0)
    cout << "Zero" << endl;
  return 0;
 }
    
