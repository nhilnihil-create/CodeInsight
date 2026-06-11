#include<bits/stdc++.h>
using namespace std;
int s[100010];
int n,nu,ans,cnt;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&nu);
		if(nu==i)
		{
			if(cnt){cnt=0;continue;}
			ans++;
			cnt=1;		
		}
		else cnt=0;
	}
	cout<<ans<<endl;
	return 0;
}
