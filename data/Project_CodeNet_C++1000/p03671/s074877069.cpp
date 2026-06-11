#include<iostream>
using namespace std;
int main()
{
    int a,b,c,x,y,z;
    cin>>a>>b>>c;

    x=a+b;y=b+c;z=a+c;

    if(y<x&&y<z)
       {
           cout<<y<<endl;
       }
    else if(x<y&&x<z)
        {
            cout<<x;
        }
    else
    {
        cout<<z<<endl;
    }
   cout<<endl;





    return 0;
}
