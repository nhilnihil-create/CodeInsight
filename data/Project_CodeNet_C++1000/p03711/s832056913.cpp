#include<iostream>
using namespace std;
int main()
{
    int x,y,a,b;
    cin>>x>>y;
    if(x==1 || x==3 || x==5 || x==7 || x==8 || x==10 || x==12)
    {
        a=1;
    }
    else if(x==4 || x==6 || x==9 || x==11)
    {
        a=2;
    }
    else if(x==2)
    {
        a=3;
    }
    if(a==1)
    {
        if(y==1 || y==3 || y==5 || y==7 || y==8 || y==10 || y==12)
        {
            b=1;
        }
        else
        {
            b=0;
        }
    }
    else if(a==2)
    {
        if(y==4 || y==6 || y==9 || y==11)
        {
            b=1;
        }
        else
        {
            b=0;
        }
    }
    else if(a==3)
    {
        if(y==2)
        {
            b=1;
        }
        else
        {
            b=0;
        }
    }
    if(b==1)
    {
        cout<<"Yes"<<endl;
    }
    else if(b==0)
    {
        cout<<"No"<<endl;
    }
    return 0;
}
