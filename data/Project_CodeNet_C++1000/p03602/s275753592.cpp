#include<bits/stdc++.h>
using namespace std;
#define nmax 305
long long a[nmax][nmax],ans=0;
bool ok[nmax][nmax];
int n;
int main()
{
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    bool o=true;
    for (int k=1;k<=n;k++)
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
        if (a[i][j]>a[i][k]+a[k][j]||(a[i][j]==0 &&i!=j))o=false;
    if (o==false)
    {
        cout<<-1;
        return 0;
    }
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
        ok[i][j]=true;
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
    for (int k=1;k<=n;k++)
        if (a[i][j]==a[i][k]+a[k][j]&& a[i][k]!=0 && a[k][j]!=0)ok[i][j]=false;
    for (int i=1;i<=n;i++)
    for (int j=i+1;j<=n;j++)
        if (ok[i][j]==true)ans=ans+a[i][j];
    cout<<ans;
    return 0;
}
