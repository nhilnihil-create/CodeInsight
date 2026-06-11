#include<bits/stdc++.h>
#define up(l,r,i) for(int i=l;i<=r;i++)
#define dn(r,l,i) for(int i=r;i>=l;i--)
using namespace std;
const int MAXN =100 +3;
const int MAXM =100000 +3;
int N,W,w[MAXN],v[MAXN];
map <pair<int,int>,pair<bool,int> > mp;
int dfs(int i,int j){
	if(i==1) return j>=w[1]?v[1]:0;
	if(mp[make_pair(i,j)].first) 
	return mp[make_pair(i,j)].second;
	mp[make_pair(i,j)].first=true;
	int t0=dfs(i-1,j),t1=j-w[i]>=0?dfs(i-1,j-w[i])+v[i]:0;
	return mp[make_pair(i,j)].second=max(t0,t1);
}
int main()
{
	scanf("%d%d",&N,&W);
	up(1,N,i) scanf("%d%d",&w[i],&v[i]);
	printf("%d\n",dfs(N,W));
	return 0;
} 
