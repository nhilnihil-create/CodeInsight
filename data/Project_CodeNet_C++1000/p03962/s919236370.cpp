#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d=0;
    cin>>a>>b>>c;
    if(a!=b && b!=c && c!=a)
    {
        d=3;
    }
    else if(a==b && b!=c && c!=a)
    {
        d=2;
    }
    else if(a!=b && b==c && c!=a)
    {
        d=2;
    }
    else if(a!=b && b!=c && c==a)
    {
        d=2;
    }
    else
    {
        d=1;
    }
    cout<<d<<endl;
    return 0;
}
