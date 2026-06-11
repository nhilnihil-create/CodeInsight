#include <iostream>
using namespace std;

int main()
{
  int num1, num2, agg;
  agg = 0;

  cin >> num1 >> num2;
  agg = num1 + num2;

  if(agg >= 10)
  cout << "error" << endl;
  else
  cout << agg << endl;
}
