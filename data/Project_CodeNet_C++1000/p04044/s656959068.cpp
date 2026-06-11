#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
string s[110];
int main()
{
	int n,l;
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++) cout<<s[i];
	cout<<endl;
}