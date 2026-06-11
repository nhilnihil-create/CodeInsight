#include <iostream>

using namespace std;

int main()
{

int a,b,c,x,y,z;
cin>>a>>b>>c;
x=a+b;
y=a+c;
z=c+b;
if(x<y&&x<z)
       cout<<x;
else if(y<x&&y<z)
       cout<<y;
else if(z<x&&z<y)
       cout<<z;
else
       cout<<x;




    return 0;
}