#include<bits/stdc++.h>
using namespace std;
const int maxn=(1e5+10);
int n,ans[maxn];
string s;
bool valid()
{
	for(int i=0;i<n;i++)
	{
		int a=i,b=(i+1)%n,c=(i+2)%n;
		if(((s[b]=='x')^ans[b]^ans[a])!=ans[c])
			return false;
	}
	return true;
}
int main()
{
	cin>>n>>s;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
		{
			ans[0]=i,ans[1]=j;
			for(int i=2;i<n;i++)
				ans[i]=(s[i-1]=='x')^ans[i-1]^ans[i-2];
			if(valid())
			{
				for(int i=0;i<n;i++)
					cout<<(ans[i]?'W':'S');
				return 0;
			}
		}
	cout<<-1<<endl;
	return 0;
}