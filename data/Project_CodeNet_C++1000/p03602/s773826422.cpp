#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=305;
ll sum;
int a[N][N],p[N][N];
int n;
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin>>a[i][j],sum+=a[i][j];
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(a[i][k]+a[k][j]<a[i][j])
                {
                    cout<<-1;
                    return 0;
                }
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(a[i][k]+a[k][j]==a[i][j]&&i!=k&&k!=j&&i!=j)
                    p[i][j]=1;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(p[i][j])
                    sum-=a[i][j];
    cout<<sum/2;
    return 0;
}
