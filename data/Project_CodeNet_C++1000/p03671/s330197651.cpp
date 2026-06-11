#include <iostream>
using namespace std;

int main()
{
  int bell1, bell2, bell3, price1, price2, price3;
  price1 = 0;
  price2 = 0;
  price3 = 0;

  cin >> bell1 >> bell2 >> bell3;
  price1 = bell1 + bell2;
  price2 = bell2 + bell3;
  price3 = bell3 + bell1;

  if(price1<=price2)
  {
    if(price1 <= price3)
    cout << price1 << endl;
    else
    cout << price3 << endl;
  }

  else if(price2<=price3)
  {
    if(price2<=price1)
    cout << price2 << endl;
    else
    cout << price1 << endl;
  }

  else if(price3<=price1)
  {
    if(price3<=price2)
    cout << price3 << endl;
    else
    cout << price2 << endl;
  }

}
