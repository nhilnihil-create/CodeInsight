#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,cnt0=0,prod=1,flag=0;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==0)
        {
            cnt0++;
        }
    }
    if(n%2==1)
    {
        if(cnt0!=1)
        {
            cout<<0;
            flag=1;
        }
        else
        {
            sort(a,a+n);
            for(ll i=1;i<n;i=i+2)
            {
                if(a[i]==a[i+1])
                {
                    prod=(prod*2)%1000000007;
                }
                else
                {
                    cout<<0;
                    flag=1;
                    break;
                }
            }
        }
    }
    else
    {
        if(cnt0>0)
        {
            cout<<0;
            flag=1;
        }
        else
        {
            sort(a,a+n);
            for(int i=0;i<n;i=i+2)
            {
                if(a[i]==a[i+1])
                {
                    prod=(prod*2)%1000000007;
                }
                else
                {
                    cout<<0;
                    flag=1;
                    break;
                }
            }
        }
    }
    if(flag==0)
    {
    cout<<prod;
    }
    return 0;
}
