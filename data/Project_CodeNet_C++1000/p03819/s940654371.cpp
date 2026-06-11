#include<cstdio>
#include<algorithm>
#define ls k<<1,l,mid
#define rs k<<1|1,mid+1,r
#define ROF(i,s,t) for(register int i=s;i>=t;--i)
#define FOR(i,s,t) for(register int i=s;i<=t;++i)
using namespace std;
int n,m,tail;
const int N=800011;
int ans[N];
namespace Segment_Tree{
	int tr[N];
	inline void modify(int x,int y,int v,int k=1,int l=0,int r=m){
		if(x<=l&&r<=y){
			tr[k]+=v;
			return;
		}
		int mid=(l+r)>>1;
		if(x<=mid)modify(x,y,v,ls);
		if(mid<y)modify(x,y,v,rs);
	}
	inline int query(int x,int k=1,int l=0,int r=m){
		if(l==r)return tr[k];
		int mid=(l+r)>>1;
		if(x<=mid)return query(x,ls)+tr[k];
		return query(x,rs)+tr[k];
	}
}
using namespace Segment_Tree;
struct node{
	int l,r,len;
	inline bool operator<(node A)const{
		return len>A.len;
	}
}q[N];
int main(){
	//freopen("train.in","r",stdin);
	//freopen("train.out","w",stdout);
	scanf("%d%d",&n,&m);
	FOR(i,1,n){
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].len=q[i].r-q[i].l+1;
		modify(q[i].l,q[i].r,1);
	}
	sort(q+1,q+n+1);
	ROF(i,m,1){
		while(tail<=n&&q[tail+1].len>=i)++tail,modify(q[tail].l,q[tail].r,-1);
		ans[i]=tail; 
		for(register int j=0;j<=m;j+=i)
			ans[i]+=query(j);
	}
	FOR(i,1,m)
		printf("%d\n",ans[i]);
	return 0;
} 