#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=200010;
string s;
int vis[28],l[maxn],r[maxn],num,now,cnt=26,len,last;
char ret,ans;
int main()
{
	cin>>s;
	len=s.length();
	r[0]=len-1;
	for(int i=len-1;i>=0;i--)
		if(!vis[s[i]-'a'])
		{
			cnt--;
			vis[s[i]-'a']=1;
			if(cnt==0)
			{	
				l[num++]=i;
				r[num]=i-1;	
				cnt=26;
				memset(vis,0,sizeof(vis));
			}
		}
//	cout<<num<<endl;
	l[num]=0;
	now=0;
	for(int i=num;i>=0;i--)
	{
		memset(vis,0,sizeof(vis));
		for(int j=now;j<=r[i];j++) vis[s[j]-'a']=1;
		for(int j=0;j<26;j++)
			if(!vis[j])
			{
				ret=j+'a';
				cout<<ret;
				ans=ret;
				break; 
			}
		for(int j=now;j<len;j++)
			if(s[j]==ret)
			{
				now=j+1;
				break;
			}
	}
	return 0;
} 