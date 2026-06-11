#include<bits/stdc++.h>
using namespace std;
int a[15];
long long ans,k;
string s;
void dfs(long long cn,int st)
{
	if(st==s.size())
	{
		k+=cn;
		ans+=k;
		return;
	}
	long long tmp=k;
	dfs(cn*10+a[st+1],st+1);
	k=tmp+cn;
	dfs(a[st+1],st+1);
}
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
		a[i+1]=(s[i]-'0');
	dfs(a[1],1);
	cout<<ans;

	return 0;
}
