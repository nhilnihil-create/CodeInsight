#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,t,l,x[N],w[N],ans[N],q[N];
typedef pair<int,int> pii;
pii p[N];
bool cmp(int a,int b){return p[a]<p[b];}
int main()
{
	scanf("%d%d%d",&n,&l,&t);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&w[i]);
		if (w[i]==2) w[i]=-1;
		p[i]=pii((l+(x[i]+w[i]*t)%l)%l,w[i]);
		q[i]=i;
	}
	sort(q+1,q+n+1,cmp);
	for (int i=1;i<=n;i++) q[i+n]=q[i];
	int cnt=0;
	for (int i=1;i<=n;i++)
	if (w[i]!=w[1]){
		int len=2*t,dis=(w[1]*(x[i]-x[1])+l)%l;
		if (len>=dis) len-=dis,cnt++;
		cnt+=len/l;
	}
	int id=(n+(1+w[1]*cnt)%n)%n,pos;
	if (id==0) id=n;
	for (int i=1;i<=n;i++) if (q[i]==1) pos=i;
	for (int i=0;i<n;i++) ans[id]=p[q[pos+i]].first,id=(id==n?1:id+1);
	for (int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}