#include<bits/stdc++.h>
using namespace std;
long long  modl(long long a, long long b, long long c) 
{
    long long res, t;
    res = 1 % c;
    t = a % c;
    while (b)
    {
        if (b & 1)
        {
            res = res * t % c;
        }
        t = t * t % c;
        b >>= 1;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,temp=1,i;
    long long int var;
    cin>>n;
    long int mod=pow(10,9)+7;
    vector<long long int> a(n);
    if(n%2==0)
    {
    for(i=0;i<n;i++)
    {
        cin>>var;
        if(var%2==0)
        {temp=0;
        break;}
        else
        {
            a[var/2]++;
        }
        if(a[var/2]>2)
        {
            temp=0;
            break;
        }
    }
    }
    else
    {
    for(i=0;i<n;i++)
    {
        cin>>var;
        if(var%2!=0)
        {temp=0;
        break;}
        else
        {
            a[var/2]++;
        }
        if(a[var/2]>2)
        {
            temp=0;
            break;
        }
    }
    if(a[0]!=1)
    temp=0;
    }
    if(temp==0)
    {
        cout<<0;
    }
    else
    cout<<modl(2,(n/2),mod)%mod;
    
    return 0;
}