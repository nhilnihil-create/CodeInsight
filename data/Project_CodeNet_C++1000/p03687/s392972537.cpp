
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=10001;
char s[maxn];
int ans[maxn],lst[maxn];
signed main()
{
	cin>>s+1;
	int len=strlen(s+1);
	for(int i=1;i<=len;i++)
	{
		ans[s[i]]=max(ans[s[i]],i-lst[s[i]]-1),lst[s[i]]=i;
	}
	int anss=1e9;
	for(int i='a';i<='z';i++)
	{
		ans[i]=max(ans[i],len-lst[i]);
		anss=min(anss,ans[i]);
	}
	cout<<anss;
    
}
/*
规则就是每次相邻二选一产生一个新的串
whbrjpjyhsrywlqjxdbrbaomnw
*/