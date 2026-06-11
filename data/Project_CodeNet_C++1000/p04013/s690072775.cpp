#include<bits/stdc++.h>
using namespace std;

int n,k;
int arr[55];
long long dp[55][3000][55];

long long f(int pos,int sum,int counter)
{
   //cout<<pos<<" "<<sum<<endl;
   if(pos==n)
   {
       if(sum>0&&(sum%counter==0)&&sum/counter==k)return 1;
       else return 0;
   }


    if(dp[pos][sum][counter]!=-1)return dp[pos][sum][counter];

    long long ans=0;

    ans+=f(pos+1,sum+arr[pos],counter+1);
    ans+=f(pos+1,sum,counter);

    return dp[pos][sum][counter]=ans;
}


int main()
{

    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>arr[i];
    memset(dp,-1,sizeof dp);
    cout<<f(0,0,0)<<endl;
}
