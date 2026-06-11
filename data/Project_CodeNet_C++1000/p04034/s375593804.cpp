#include<bits/stdc++.h>
using namespace std;
const int N=100000;
int f[N],a[N];
int main()
{
    int n,m;
    cin>>n>>m;
    int x[N],y[N];
    for(int i=1;i<=n;i++)
    {
        f[i]=1;
        if(i==1)
            a[i]=1;
        else
            a[i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=m;i++)
    {
        f[x[i]]--;
        f[y[i]]++;
        if(a[x[i]]==1)
        {
            a[y[i]]=1;
        }
        if(f[x[i]]==0)
            a[x[i]]=0;
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1)
            sum++;
    }
    cout<<sum<<endl;
    return 0;
}