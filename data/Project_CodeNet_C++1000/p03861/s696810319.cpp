#include <iostream>
using namespace std;
 
int main() 
{
  long long int a, b, x, count;
  cin >> a >> b >> x;
  if (a == 0) 
    count = b / x + 1;
  else
    count =  b / x - (a - 1) / x;
  cout << count << endl;
}