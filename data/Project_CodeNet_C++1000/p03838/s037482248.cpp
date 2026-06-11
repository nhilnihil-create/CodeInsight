#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int x,y;
    cin>>x>>y;
    if(y==0)
    {
        if(x<=0)
        {
            cout<<abs(x)<<endl;
        }
        else
        {
            cout<<1+x<<endl;
        }
    }
    else if(x==0)
    {
        if(y>=0)
        {
            cout<<y<<endl;
        }
        else
        {
            cout<<1+abs(y)<<endl;
        }
    }
    else if(x<0&&y>=0||(x>=0&&y<0))
    {
        cout<<abs(abs(y)-abs(x))+1<<endl;
        return 0;
    }
    else if(y>=x&&y>=0&&x>=0)
    {
        cout<<y-x<<endl;
    }
    else if(y>=x&&y>=0&&x<0)
    {
        if(-x<=y)
        {
            int min1=min(1+y+x,y-x);
            cout<<abs(min1)<<endl;
        }
        else
        {
            cout<<abs(y-x)<<endl;
        }
    }
    else if(y>=x&&y<0&&x<0)
    {
        cout<<abs(y-x)<<endl;
    }
    else if(y<x&&x>=0&&y>=0)
    {
        cout<<2+abs(-y+x)<<endl;
    }
    else if(y<x&&x>=0&&y<0)
    {
        cout<<1+abs(y+x)<<endl;
    }
    else if(y<x&&y<0&&x<0)
    {
        cout<<2+abs(y)-abs(x)<<endl;
    }
    return 0;
}
