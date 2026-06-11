#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
priority_queue< pair<int,int> > pq;
vector<int> v[MN+5]; 
int a[MN+5];
int main()
{
	int n,m,i,j;
	long long s=0,ss=0,ans=0;
	n=read();m=read();
	for(i=1;i<=n;++i)a[i]=read();
	for(i=1;i<n;++i)
		if(a[i+1]>a[i])s+=a[i+1]-a[i],v[a[i]].push_back(a[i+1]);
		else s+=a[i+1]+m-a[i],pq.push(make_pair(-a[i+1],a[i]-m)),ss+=a[i]-m,v[a[i]].push_back(a[i+1]+m);
	for(i=1;i<=m;++i)
	{
		ans=max(ans,(long long)pq.size()*(i-1)-ss);
		while(pq.size()&&-pq.top().first==i)ss-=pq.top().second,pq.pop();
		for(j=0;j<v[i].size();++j)pq.push(make_pair(-v[i][j],i)),ss+=i;
	}
	printf("%lld",s-ans);
}