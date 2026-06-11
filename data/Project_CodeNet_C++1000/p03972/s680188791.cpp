#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int M=1e5+5;
struct Event
{
	int w,k;
	void read(int k_)
	{
		k=k_;
		scanf("%d",&w);
	}
	bool operator<(const Event &B) const
	{
		return w<B.w;
	}
}e[M*2];
vector<Event> vec;

int main()
{
	int n,m; scanf("%d%d",&n,&m);
	int k=0;
	for(int i=0;i<n;i++)
		e[k++].read(0);
	for(int i=0;i<m;i++)
		e[k++].read(1);
	n++; m++;
	int c=0,r=0;
	LL ans=0;
	sort(e,e+k);
	for(int i=0;i<k;i++)
	{
		if(e[i].k) ans+=1LL*e[i].w*(n-r),c++;
		else ans+=1LL*e[i].w*(m-c),r++;
	}
	printf("%lld\n",ans);
	return 0;
}
