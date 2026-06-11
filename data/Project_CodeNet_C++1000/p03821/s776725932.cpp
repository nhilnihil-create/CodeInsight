#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("04.txt","r",stdin);
    int mod,n,i,a[100001]={0},b[100001]={0};
    long long tim[100001]={0};
    long long mul,done=0;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i]>>b[i];
    for(i=0;i<n;i++)
    {
        mod=a[i]%b[i];
        if(mod)
            tim[i]=b[i]-mod;
    }
    for(i=n-2;i>=0;i--)
    {
        if(tim[i]>=tim[i+1])
            continue;
        mul=(tim[i+1]-tim[i])/b[i];
        tim[i]+=mul*b[i];
        if(tim[i]<tim[i+1])
            tim[i]+=b[i];
    }
    done=tim[n-1];
    for(i=n-2;i>=0;i--)
    {
        done+=(long long)(tim[i]-tim[i+1]);
    }
    cout<<done;
    return 0;
}
