//love yjl forever
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
const int INF=0x3f3f3f3f,N=2e5+5;
ll n,k,tot;
ll lowbit(ll x)
{
	return x&-x;
}
ll a[N],b[N],c[N];
struct node{
	ll num,in;
}s[N];
ll sum(ll x)
{
	ll ans=0;
	while(x>0)
	{
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}
void add(ll x,ll y)
{
	while(x<=tot)
	{
		c[x]+=y;
		x+=lowbit(x);
	}
}
bool cmp1(node x,node y)
{
	return x.num<y.num;
}
bool cmp2(node x,node y)
{
	return x.in<y.in;
}
int main()
{
/*	freopen("","r",stdin);
	freopen("","w",stdout);*/
	int i;
	cin>>n>>k;
	s[0].in=0;
	s[0].num=0;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		a[i]-=k;
		s[i].num=s[i-1].num+a[i];
		s[i].in=i;
	}
	
	sort(s,s+n+1,cmp1);
	

	for(i=0;i<=n;i++)
	{
		if(i==0||s[i].num!=s[i-1].num)
		{
			b[i]=++tot;
		}
		else 
			b[i]=b[i-1];
	}
	
	for(i=0;i<=n;i++)
		s[i].num=b[i];
		
	sort(s,s+n+1,cmp2);
//	for(i=0;i<=n;i++)
//		cout<<s[i].num<<" ";
//	cout<<endl;
	ll ans=0;
	for(i=0;i<=n;i++)
	{
		ans+=sum(s[i].num);
		add(s[i].num,1);
	}
	cout<<ans<<endl;
}