#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,a,b,x,y;
    cin>>n>>a>>b;

    if(n==1)
    {
        if(a==b)
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }
    else
    {
        if(a>b)
            cout<<"0"<<endl;
        else
        {
            x=a*(n-2);
            y=b*(n-2);
            cout<<(y-x)+1<<endl;
        }

    }
}

