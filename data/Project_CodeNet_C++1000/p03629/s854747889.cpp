#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int maxn=200005;
int vis[27],res,r[maxn],l[maxn],cnt;
char s[maxn];
int main()
{
	cin>>s;
	int len=strlen(s);
	res=26;r[0]=len-1;
	for(int i=len-1;i>=0;i--)
		if(!vis[s[i]-'a'])
		{
			vis[s[i]-'a']=1;res--;
			if(!res)
			{
				l[cnt]=i;r[++cnt]=i-1;
				memset(vis,0,sizeof(vis));res=26;
			}
		}
	int last=0;l[cnt]=0;
	char t;
	for(int i=cnt;i>=0;i--)
	{
		memset(vis,0,sizeof(vis));res=26;
		for(int j=last;j<=r[i];j++)vis[s[j]-'a']=1;;
		for(int j=0;j<26;j++)
			if(!vis[j])
			{
				printf("%c",j+'a');
				t=j+'a';break;
			}
		for(int j=last;j<len;j++)
			if(s[j]==t)
			{
				last=j+1;break;
			}
	}
	
}