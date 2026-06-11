#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e2+5;
ll n,a[N][N],f[N];
struct node{
	ll u,v,d;
	node(){}
	node(ll uu,ll vv,ll dd){
		u=uu,v=vv,d=dd;
	}
};
vector<node> v;
bool cmp(node a,node b){
	return a.d>b.d;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	bool flag=true;
	for(int i=1;i<=n&&flag;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			bool ned=true;
			for(int k=1;k<=n;k++)
			{
				if(k==j||k==i)	continue;
				if(a[i][j]>a[i][k]+a[k][j])
					flag=false;
				if(a[i][j]==a[i][k]+a[k][j]) 
					ned=false; 
			}		
			if(ned)	v.push_back(node(i,j,a[i][j]));
		}
	} 
	if(v.size()<n-1||flag==false)	cout<<-1<<'\n';
	else{
		ll res=0;
		sort(v.begin(),v.end(),cmp);
		for(int i=0;i<v.size();i++)
		{
			ll x=v[i].u,y=v[i].v,val=v[i].d;
		//	cout<<x<<' '<<y<<' '<<val<<'\n';
			res+=val;
		}
		cout<<res<<'\n';
	}
	return 0;
}