#include<cstdio>
#include<algorithm>
struct node{
	int l,r;
	bool operator<(node b)const{
		return r-l<b.r-b.l;
	}
}a[500100];
int tree[2001000],n,m;
void pushdown(int t){
	tree[t*2]+=tree[t];
	tree[t*2+1]+=tree[t];
	tree[t]=0;
}
void modify(int t,int l,int r,int L,int R){
	if(L>r||l>R)return;
	if(L<=l&&r<=R){
		tree[t]++;
		return;
	}
	pushdown(t);
	int mid=(l+r)/2;
	modify(t*2,l,mid,L,R);
	modify(t*2+1,mid+1,r,L,R);
}
int query(int t,int l,int r,int pos){
	if(l==r)return tree[t];
	int mid=(l+r)/2;
	pushdown(t);
	if(pos<=mid)return query(t*2,l,mid,pos);
	return query(t*2+1,mid+1,r,pos);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].l,&a[i].r);
	std::sort(a+1,a+n+1);
	int now=1;
	for(int i=1;i<=m;i++){
		while(a[now].r-a[now].l+1<i&&now<=n){
			modify(1,1,m,a[now].l,a[now].r);
			now++;
		}
		int res=0;
		for(int j=i;j<=m;j+=i)
			res+=query(1,1,m,j);
		printf("%d\n",res+n-now+1);
	}
	return 0;
}