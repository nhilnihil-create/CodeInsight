#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int a,b,c;
  int count=0;
  int ac,bc,cc;

  cin >> a >> b >> c;

  ac=a;
  bc=b;
  cc=c;

  bool flag=true;
  while (ac%2==0 && bc%2==0 && cc%2==0)
  {
    int a2=ac/2;
    int b2=bc/2;
    int c2=cc/2;

    ac=b2+c2;
    bc=c2+a2;
    cc=a2+b2;
    count++;

    if (ac==a && bc==b && cc==c)
    {
      flag=false;
      break;
    }
    
  }
  

  if (flag)
  {
    cout << count << endl;
  }else
  {
    cout << -1 << endl;
  }  

  return 0;
}