#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  if(n>0 && n<101)
  {
    int candy=0;
    for(int i = 1; i<=n; i++)
    {
      candy += i;
    }
    cout << candy<< endl;
  }
  return 0;
}