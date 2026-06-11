#include <iostream>
using namespace std;

int main()
{
  int a = 0, b = 0, c = 0, total = 1;
  cin >> a >> b >> c;
  
  if(b!=a && c!=b && c!=a)
    total = 3;
  if(b!=a && c==a)
    total=2;
  if(b==a && c!=a)
    total = 2;
  if(b==c && b!=a)
	total=2;
  
  cout << total << endl;
}