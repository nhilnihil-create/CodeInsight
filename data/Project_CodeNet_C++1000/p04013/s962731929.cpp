#include<bits/stdc++.h>
#define ll long long
const int mod=1e9+7;
using namespace std;

int a[100];
ll dp[55][2550];
int main()
{
    //freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    int N,A;cin>>N>>A;
    for(int i=1;i<=N;i++)
    {
        cin>>a[i];
    }
    ll sum=0,ans=0;
    dp[0][0]=1;
    for(int i=1;i<=N;i++)
        for(int j=i;j>=1;j--)
            for(int k=2550;k>=a[i];k--)
                dp[j][k]+=dp[j-1][k-a[i]];
    for(int i=1;i<=N;i++)
    {
        sum+=dp[i][i*A];
    }
    cout<<sum<<endl;
}

