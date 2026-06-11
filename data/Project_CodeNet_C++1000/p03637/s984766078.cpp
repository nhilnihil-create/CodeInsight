/*
        Author: Prokash
                CSE48, JU

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    FAST;
    ll n,t,i,d,d2;
    cin>>t;
    d=0;
    d2=0;
    for(i=0; i<t; i++)
    {
        cin>>n;
        if(n%4==0)
        {
            d++;
        }
        if(n%4==2)
        {
            d2++;
        }
    }
    ll s=t/2;
    if(d>=s)
    {
        cout<<"Yes"<<endl;
    }
    else if((d2/2+d)>=s)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}