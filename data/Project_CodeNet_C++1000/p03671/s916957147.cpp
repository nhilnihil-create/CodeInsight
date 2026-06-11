#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,x,y,z;
    cin>>a>>b>>c;
    x=a+b;
    y=b+c;
    z=c+a;
    if(x>y && x>z)
    {
        if(y>z)
        {
            cout<<z<<endl;
        }
        else
        {
            cout<<y<<endl;
        }
    }
    else if(y>z && y>x)
    {
        if(z>x)
        {
            cout<<x<<endl;
        }
        else
        {
            cout<<z<<endl;
        }
    }
    else if(z>x && z>y)
    {
        if(x>y)
        {
            cout<<y<<endl;
        }
        else
        {
            cout<<x<<endl;
        }
    }
    else if(x==y && y==z)
    {
        cout<<x<<endl;
    }
    return 0;
}
