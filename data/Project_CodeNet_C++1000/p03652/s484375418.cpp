#include<bits/stdc++.h>
using namespace std;
const int maxn=330;
int a[maxn][maxn],n,lat[maxn],m,cnt[maxn],top[maxn];
struct node{
	int cnt,x,vis;
	node(int a,int b,int c){cnt=a;x=b;vis=c;}
	friend bool operator<(node a,node b){
		return a.cnt<b.cnt;
	}
};
int stac[maxn],topp;
	
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	int ans=INT_MAX; 
	priority_queue<node>q;
	for(int i=1;i<=n;++i)cnt[a[i][1]]++,top[i]=1,lat[a[i][1]]=1;
	for(int i=1;i<=m;++i)q.push(node(cnt[i],i,1));
	while(q.size()){
		int x=q.top().x;
		if(q.top().vis!=lat[x]){q.pop();continue;}
		ans=min(ans,cnt[x]);
		q.pop();
		topp=0;
		for(int i=1;i<=n;++i)
			if(a[i][top[i]]==x){
				if(top[i]==m)continue;
				cnt[a[i][top[i]+1]]++;
				top[i]++;
				stac[++topp]=a[i][top[i]];
			}
		topp=unique(stac+1,stac+1+topp)-stac-1;
		for(int i=1;i<=topp;++i){
			lat[stac[i]]++;
			q.push(node(cnt[stac[i]],stac[i],lat[stac[i]]));
		}
	}
	cout<<ans;
}