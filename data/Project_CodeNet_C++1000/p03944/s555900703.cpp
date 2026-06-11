#include <bits/stdc++.h>
using namespace std;

int main()
{
    int xmin=0,ymin=0,xmax,ymax,n;
    cin>>xmax>>ymax>>n;
    for(int i=0;i<n;i++)
    {
        int a,x,y;
        cin>>x>>y>>a;
        if(a==1)    xmin=max(x,xmin);
        if(a==2)    xmax=min(x,xmax);
        if(a==3)    ymin=max(y,ymin);
        if(a==4)    ymax=min(ymax,y);

    }
    if(xmin<xmax && ymin<ymax)
        cout<<(xmax-xmin)*(ymax-ymin);
    else
        cout<<0;
    return 0;
}

