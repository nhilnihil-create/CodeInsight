#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<set>
#include<map>
using namespace std;
template<typename __T>
inline void read(__T &x)
{
    x=0;
    int f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')	f=-1;c=getchar();}
    while(isdigit(c))	{x=x*10+c-'0';c=getchar();}
    x*=f;
}
string str;
int n;
int mxpos[26][200005];
int dp[200005];
int main()
{
	cin>>str;
	n=str.size();
	memset(mxpos,23,sizeof(mxpos));
	for(int i=0;i<n;i++)
		mxpos[str[i]-'a'][i]=i;
	for(int i=0;i<26;i++)
		for(int j=n-2;j>=0;j--)
			mxpos[i][j]=min(mxpos[i][j],mxpos[i][j+1]);
	for(int i=n-1;i>=0;i--)
	{
		int gg=1234567;
		for(int j=0;j<26;j++)
		{
			if(mxpos[j][i+1]<1234567)
				gg=min(gg,dp[mxpos[j][i+1]]);
			else
				gg=0;
		}
		if(gg==1234567)	gg=0;
		dp[i]=gg+1;//cout<<i<<' '<<str[i]<<' '<<dp[i]<<endl;
	}
	for(int j=0;j<26;j++)
		if(mxpos[j][0]>1234567)
		{
			cout<<(char(j+'a'))<<endl;
			return 0;
		}
	bool fg=0;
	int st=0;
	int mxv=123456;
	for(int i=0;i<26;i++)
		mxv=min(mxv,dp[mxpos[i][0]]);//cout<<mxv<<endl;
//	cout<<"WTF"<<mxpos[0][0]<<endl;
	for(int j=0;j<26;j++)
		if(mxv==dp[mxpos[j][0]])
		{//cout<<"WTF"<<dp[0]<<' '<<j<<' '<<mxpos[j][0]<<' '<<dp[mxpos[j][0]]<<endl;
			st=mxpos[j][0];
			break;
		}
//	st=mxpos[0][0];
	for(int i=st;i<=n && fg==0;)
	{
		cout<<str[i];
		for(int j=0;j<26;j++)
		{
			if(mxpos[j][i+1]<1234567)
			{
				if(dp[i]==dp[mxpos[j][i+1]]+1)
				{
					i=mxpos[j][i+1];
					break;
				}
			}
			else
			{
				cout<<(char(j+'a'))<<endl;
				fg=1;
				break;
			}
		}
	}
	return 0;
}
