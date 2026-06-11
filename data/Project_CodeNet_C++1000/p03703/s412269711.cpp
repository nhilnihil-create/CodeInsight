#include<cstdio>
#include<algorithm>
using std::sort;
#define int long long
struct node{
	int id,val,VAL;
}c[200100];
int tree[1000100],n,k,a[200100],sum[200100],ans;
bool cmp1(node x,node y){
	return x.val<y.val;
}
bool cmp2(node x,node y){
	return x.id<y.id;
}
void modify(int t,int l,int r,int pos){
	if(l==r){
		tree[t]++;
		return;
	}
	int mid=(l+r)/2;
	if(pos<=mid)modify(t*2,l,mid,pos);
	else modify(t*2+1,mid+1,r,pos);
	tree[t]=tree[t*2]+tree[t*2+1];
}
int query(int t,int l,int r,int L,int R){
	if(L>r||l>R)return 0;
	if(L<=l&&r<=R)return tree[t];
	int mid=(l+r)/2;
	return query(t*2,l,mid,L,R)+query(t*2+1,mid+1,r,L,R);
}
signed main(){
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
		c[i].id=i,c[i].val=sum[i]-k*i;
	sort(c+1,c+n+1,cmp1);
	c[0].val=-0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n;i++)
		if(c[i].val!=c[i-1].val)c[i].VAL=i;
		else c[i].VAL=c[i-1].VAL; 
	sort(c+1,c+n+1,cmp2);
	for(int i=1;i<=n;i++){
		if(c[i].val>=0)ans++;
		ans+=query(1,1,n,1,c[i].VAL);
		modify(1,1,n,c[i].VAL);
	}
	printf("%lld\n",ans);
}