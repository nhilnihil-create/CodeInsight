#include <bits/stdc++.h>
#define int LL
using namespace std;
typedef long long LL;
const int MAX_N=100005;
const int Mod=1e9+7;
int n;
int m;
int x[MAX_N];
int y[MAX_N];
int xi[MAX_N];
int yi[MAX_N]; 
int pre[MAX_N];
int sum(int seg[],int nm)
{
	for(int i=1;i<nm;i++)
	{
		pre[i]=pre[i-1]+seg[i];
	}
	int l=1,r=nm-1;
	int res=pre[nm-1];
	int sum=res;
	while(l<nm && r>0)
	{ 
		res+=pre[nm-1]-pre[l]-(pre[nm-1]-pre[r-1]);
		res%=Mod;
		l++;
		r--;
		sum+=res;
		sum%=Mod;
	}
	return sum;
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<=m;i++)cin>>y[i];
	for(int i=1;i<n;i++)xi[i]=x[i+1]-x[i];
	for(int i=1;i<m;i++)yi[i]=y[i+1]-y[i];
	cout<<sum(xi,n)*sum(yi,m)%Mod<<endl;

	return 0;
}