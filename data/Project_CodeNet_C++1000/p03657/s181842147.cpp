#include <iostream>
using namespace std;

int main()
{
  int num1, num2, cookies;
  //cookies = 0;

  cin >> num1 >> num2;
  cookies = num1 + num2;

  if(cookies % 3 == 0)
    cout << "Possible" << endl;
  else if(num1 % 3 == 0)
    cout << "Possible" << endl;
  else if(num2 % 3 == 0)
    cout << "Possible" << endl;
  else
  cout << "Impossible" << endl;



}
