#include <bits/stdc++.h>
using namespace std;

int64_t n,res=0,a[305][305];
bool Free[305][305];

int main()
{
    cin>>n;
    for(int64_t i=1;i<=n;i++)
        for(int64_t j=1;j<=n;j++)
            cin>>a[i][j];
    for(int64_t t=1;t<=n;t++)
        for(int64_t i=1;i<=n;i++)
            for(int64_t j=1;j<=n;j++)
            {
                if(a[i][j]>a[i][t]+a[t][j])
                {
                    cout<<-1;
                    return 0;
                }
                if(a[i][j]==a[i][t]+a[t][j]&&a[i][t]>0&&a[t][j]>0)
                    Free[i][j]=true;
            }
    for(int64_t i=1;i<=n;i++)
        for(int64_t j=i+1;j<=n;j++)
            if(Free[i][j]==false)
                res+=a[i][j];
    cout<<res;
}
