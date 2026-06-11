#include<bits/stdc++.h>
#define   ll  long long int
#define   sz  1000100

using namespace std;


ll num[sz];


int main()
{


    ll n,b,s=0,k,x,y,a,i,j,d;

    cin>>n;

    for(i=1;i<=n;i++)
    {
        cin>>num[i];
        s+=num[i];
    }

    for(i=1;i<=n;i++)
    {
        num[i]=num[i-1]+num[i];

    }

        x=num[1];
        y=s-x;
        d=abs(x-y);
        a=d;



    for(i=2;i<n;i++)
    {
        x=num[i];
        y=s-x;

        d=abs(x-y);
        a=min(a,d);
    }


    cout<<a<<endl;


    return 0;
}
