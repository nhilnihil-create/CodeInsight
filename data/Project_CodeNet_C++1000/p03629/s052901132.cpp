#include<bits/stdc++.h>
using namespace std;
int l,f[2222222],nt[2222222],to[2222222],path[2222222];
char c[2222222];
int main()
{
	scanf("%s",c+1);
	l=strlen(c+1);
	for(int i=0;i<26;i++)
	{
		nt[i]=l+1;
	}
	for(int i=1;i<=l;i++)
	{
		f[i]=1e9;
	}
	f[l+1]=1e9;
	f[l+2]=0;
	for(int i=l;i>0;i--)
	{
		nt[c[i]-'a']=i;
		for(int j=0;j<26;j++)
		{
			if(f[i]>f[nt[j]+1]+1)
			{
				f[i]=f[nt[j]+1]+1;
				path[i]=j;
				to[i]=nt[j]+1;
			}
		}
	}
	for(int i=1;i<=l;i=to[i])
	{
		printf("%c",path[i]+'a');
		
	}
}