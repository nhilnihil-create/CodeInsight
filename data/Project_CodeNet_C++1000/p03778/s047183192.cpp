#include <iostream>
#include <math.h>
using namespace std;

int main()
{
   int w,a,b,sum=0;
   cin>>w>>a>>b;
   if(a>=b)
   {
      sum= a-(w+b);
      if(sum>=0)
       cout<<sum<<endl;
       else cout<<0<<endl;
       return 0;
   }
   if(b>a)
   {
       sum=b-(w+a);
       if(sum>=0)
       cout<<sum<<endl;
       else cout<<0<<endl;

       return 0;
   }

    return 0;
}
