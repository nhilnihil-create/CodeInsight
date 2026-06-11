#include<bits/stdc++.h>
using namespace std;
long long int a[310][310],w[310][310],nexts[310][310],n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            nexts[i][j]=-1;
            cin>>a[i][j];
            w[i][j]=a[i][j];
        }
    }
    for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(w[i][j]>w[i][k]+w[k][j])
            {
                w[i][j]=w[i][k]+w[k][j];
            }
        }
    }}

    long long int ans=0;
    for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(w[i][j]==w[i][k]+w[k][j] && i!=k && k!=j)
            {
                nexts[i][j]=1;
            }
        }
    }}
    bool flag=false;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            //cout<<w[i][j]<<endl;
            if(w[i][j]!=a[i][j])
            {
                flag=true;
            }
            if(nexts[i][j]==-1) ans+=(long long int)w[i][j];
        }
    }
    if(flag) cout<<"-1"<<endl;
    else cout<<ans<<endl;
}
