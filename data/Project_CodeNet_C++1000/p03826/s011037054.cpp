#include <iostream>

using namespace std;

int main()
{
   int a,b ,c,d;
   cin >>a>>b>>c>>d;
   int x = a*b;
   int y= c*d;
   if (x>=y)
   cout<<x;
   else if (y>=x)
   cout <<y;
    return 0;
}
