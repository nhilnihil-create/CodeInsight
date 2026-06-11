#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+10;
struct point{int l,r;}a[N];
int n,m,tot,ans,c[N];
vector<int>vec[N];
int sum(int x){int ret=0;while(x)ret+=c[x],x-=x&-x;return ret;}
void add(int x,int y){while(x<=n)c[x]+=y,x+=x&-x;}
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i].l,&a[i].r);
		if(a[i].l)vec[a[i].r-a[i].l+1].push_back(i);
	}
	tot=m;
	for(int i=1;i<=n;i++)
	{
		ans=0;
		for(int j=1;j<=n/i;j++)ans+=sum(i*j);
		printf("%d\n",tot+ans);
		for(auto j:vec[i])add(a[j].l,1),add(a[j].r+1,-1),tot--;
	}
}