#include <bits/stdc++.h>
using namespace std;
#define long long long
#define size 5005
const long MOD = 1e9+7;
bool dp[size];
int A[size];
pair<int,int>pos[size];
signed main()
{
    long test;
    test=1;
    // cin>>test;
    while(test--){
    long i,j,b,n,x,k,ans,most,index,c,maxi=0,temp,aw,bw,w,count,sum;
    cin>>n>>k;
    for(i=0;i<n;i++)cin>>A[i];
    sort(A,A+n);
    sum=0;
    for(i=0;i<n;i++)sum+=A[i];
    memset(dp,false,sizeof(dp));
    dp[0]=true;
    int ret=0;
    for(i=n-1;i>=0;i--)
    {
        bool up=false;
        for(j=0;j<k;j++)
        {
            if(dp[j] && j+sum>=k)up=true;
        }
        if(!up)ret++;
        sum-=A[i];
        for(j=k-1;j>=A[i];j--)
        {
            dp[j]|=dp[j-A[i]];
        }
    }
    cout<<ret;
    
    
    }
}