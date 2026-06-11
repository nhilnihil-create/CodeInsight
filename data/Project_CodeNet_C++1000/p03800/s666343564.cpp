#include<bits/stdc++.h>
using namespace std;
const int maxn=(1e5+10);
int n,r[maxn];
string s;
bool check(int a,int b,int c,char t)
{
	if(t=='o'&&!b)
	{
		if(a==c)
			return true;
		return false;
	}
	if(t=='o')
	{
		if(a==c)
			return false;
		return true;
	}
	if(!b)
	{
		if(a==c)
			return false;
		return true;
	}
	if(a==c)
		return true;
	return false;
}
int main()
{
	bool ok=false;
	cin>>n>>s;
	for(int i=0;i<4;i++)
	{
		r[0]=i/2,r[1]=i%2;
		for(int j=2;j<n;j++)
		{
			if(s[j-1]=='o')
				r[j]=r[j-2];
			else
				r[j]=1-r[j-2];
			if(r[j-1])
				r[j]^=1;
		}
		if(!check(r[n-2],r[n-1],r[0],s[n-1]))
			continue;
		if(!check(r[n-1],r[0],r[1],s[0]))
			continue;
		for(int j=0;j<n;j++)
			cout<<(r[j]?'W':'S');
		return 0;
	}
	cout<<-1<<endl;
	return 0;
}