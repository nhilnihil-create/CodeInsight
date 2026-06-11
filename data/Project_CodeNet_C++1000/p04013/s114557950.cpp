#include<iostream>
#include<cstdio>
using namespace std;
long long b,a,x;
long long dp[300][8000],ans;
int main()
{
    dp[0][0]=1;
    cin>>a>>b;
    for(int i=1;i<=a;i++)
	{
        cin>>x;
        for(int j=i;j>0;j--)
		{
            for(int k=a*b;k>=x;k--)
			{
                dp[j][k]+=dp[j-1][k-x];
            }
        }
    }
    for(int i=1;i<=a;i++)
	{
        ans+=dp[i][i*b];
    }
    cout<<ans<<endl;
    return 0;
}