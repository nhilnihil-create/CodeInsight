#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
vector<int> adj[2000005];
int n,m;
int d[2000005];
bool visited[2000005];
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	int e4=0,e2=0,od=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]%4==0)e4++;
		else if(a[i]%2==0)e2++;
		else od++;
	}
	if(od>0)
	{
		if(od==e4&&e2>0)cout<<"Yes";
		else if(od==e4+1&&e2==0)cout<<"Yes";
		else cout<<"No";
	}
	else if(od==0)
	{
		cout<<"Yes";
	}
}
	