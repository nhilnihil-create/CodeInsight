#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
map<pair<int,int>,int>jl;
int n,m,k;
void cl(int x,int y){
	for(int i=x-2;i<=x;i++)
	for(int j=y-2;j<=y;j++){
		if(i<=0||j<=0)continue;
		jl[make_pair(i,j)]++;
	}
}
ll ans[10];
int main()
{
	//freopen("H:\\c++1\\in.txt","r",stdin);
	//freopen("H:\\c++1\\out.txt","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&k);
	while(k--){
		int x,y;
		scanf("%d%d",&x,&y);
		cl(x,y);
	}
	for(auto it:jl){
		int x=it.first.first,y=it.first.second;
		if(x+2>n||y+2>m)continue;
		ans[it.second]++;
	}
	ll sum=0;
	for(int i=1;i<=9;i++)sum+=ans[i];
	ans[0]=1ll*(n-2)*(m-2)-sum;
	for(int i=0;i<=9;i++)printf("%lld\n",ans[i]);
	return 0;
}