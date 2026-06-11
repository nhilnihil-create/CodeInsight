#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N;
	cin>>N;
	vector<int> s(N);
	rep(i,N) cin>>s[i];
	vector<int> dp(N*100+1);
    dp[0]=true;
  	rep(i,N)
    {
      for(int j=N*100;j>=s[i];j--)
      {
        if(dp[j-s[i]]) dp[j]=dp[j-s[i]];
      }
    }
   	int ans=0;
  	rep(i,N*100+1)
    {
      if(i%10!=0&&dp[i]) ans=i;
    }
  cout<<ans<<endl;
}

