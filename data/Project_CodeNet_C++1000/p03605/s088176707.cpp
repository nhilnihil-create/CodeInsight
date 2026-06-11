#include <iostream>
using namespace std;

int main()
{
  string res = "No";
  int n;
  cin >> n;
  while(int a = n % 10)
  {
    if(a == 9)
      res = "Yes";
    n /= 10;
  }
  
  cout << res << endl;
  return 0;
}