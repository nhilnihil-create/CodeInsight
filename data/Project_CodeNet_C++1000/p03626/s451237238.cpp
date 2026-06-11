#include <bits/stdc++.h>
using namespace std;
char s[60];
long long dp[60];
int a[60];
const int MD=1000000007;
int main()
{
    int n;
    scanf("%d",&n);
    int t=0;
    scanf("%s",s+1);
    for(int i=1; i<=n; i++)
        if(s[i]==s[i-1])
            a[t]++;
        else
            a[++t]++;
    if(a[1]==1)dp[1]=3;
    else dp[1]=6;
    for(int i=2; i<=t; i++)
    {
        if(a[i-1]==2)
        {
            if(a[i]==2)
                dp[i]=dp[i-1]*3%MD;
            else if(a[i]==1)
                dp[i]=dp[i-1];
        }
        else if(a[i-1]==1)
        {
            if(a[i]==2||a[i]==1)
            dp[i]=dp[i-1]*2%MD;
        }
    }
    scanf("%s",s+1);
    cout<<dp[t];
    return 0;
}