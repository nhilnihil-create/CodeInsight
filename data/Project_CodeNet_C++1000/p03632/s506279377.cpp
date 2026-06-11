#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,x,y;
    cin>>a>>b>>c>>d;
    if(a<=c)
        x=c;
    else
        x=a;
    if(b<=d)
        y=b;
    else
        y=d;
    if((y-x)> 0)
        cout<<y-x;
    else
        cout<<0;
    return 0;
}
