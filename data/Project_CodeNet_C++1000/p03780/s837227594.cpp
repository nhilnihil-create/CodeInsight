#include <bits/stdc++.h>
#define N 5005
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int n,k;
int a[N];
vector <int> b[N];
bool dp[N][N];
int read()
{
	int x=0;
	char ch=' ';
	bool flag=false;
	while(!isdigit(ch))
	{
		if(ch=='-')flag=true;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return flag?-x:x;
}
int Inboard(int x)
{
	if(x>k)x=k;
	return x;
}
void Init()
{
	n=read(),k=read();
	rep(i,0,n)
	{
		a[i]=read();
		a[i]=Inboard(a[i]);
	}
	sort(a,a+n);
	rep(i,0,n)
	{
		rep(j,0,n)
		{
			if(i!=j)b[i].push_back(a[j]);
		}
	}
}
bool check(vector <int> ai,int x)
{
	if(ai.empty())return x>=k;
	if(ai.size()==1)return ai[0]>=k-x && ai[0]<k;
	memset(dp,false,sizeof(dp));
	dp[0][0]=true;
	dp[0][ai[0]]=true;
	int np=n-1;
	rep(i,1,np)
	{
		rep(j,0,k)
		{
			dp[i][j]=dp[i][j] || dp[i-1][j];
			if(j>ai[i])dp[i][j]=dp[i][j] || dp[i-1][j-ai[i]];
		//	dp[i+1][j]|=dp[i][j];
		//	dp[i+1][Inboard(j+ai[i])]|=dp[i][j];
		}
	}
	int low=k-x;
/*	rep(i,0,np)
	{
		rep(j,0,k)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	rep(i,low,k)
	{
		if(dp[np-1][i])return true;
	}
	return false;
}
void Solve()
{
	int lb=0,ub=n;
	while(lb<ub)
	{
		int mid=(lb+ub)/2;
		if(check(b[mid],a[mid]))
		{
			ub=mid;
		}
		else
		{
			lb=mid+1;
		}
	}
	cout<<lb<<endl;
}
int main()
{
	Init();
	Solve();
	return 0;
}