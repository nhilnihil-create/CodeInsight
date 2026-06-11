#include<bits/stdc++.h>
#define ll long long int
using namespace std;
	int n,a;
	
	vector<int>vec;
	ll dp[52][3000][52];
ll dfs(int pos,int sum,int cnt){
	
	if(pos==n)
	{
		if(cnt!=0 && sum%cnt==0){
			int temp=sum/cnt;
			if(temp==a){
				return 1;
			}
		}
		return 0;
	}
	if(dp[pos][sum][cnt]!=-1){
		return dp[pos][sum][cnt];
	}
	ll ans=0;
	ans+=dfs(pos+1,sum,cnt);
	ans+=dfs(pos+1,sum+vec[pos],cnt+1);
	return dp[pos][sum][cnt]=ans;
}
int main(){
	

	cin>>n>>a;
	vec.resize(n);
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		cin>>vec[i];
	}
	ll res=dfs(0,0,0);
	cout<<res<<endl;
	
	return 0;
}
