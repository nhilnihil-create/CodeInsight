#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int m,n;
struct Ask{
	int l,r;
}A[N];
int cmp(Ask x,Ask y){
	return x.r-x.l<y.r-y.l;
}
struct Tree{
	int l,r,num,flag;
}T[N*4];
void build(int x,int l,int r){
	T[x].l=l;T[x].r=r;
	if (l==r)return;
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
}
void down(int x){
	T[x*2].num+=T[x].flag;
	T[x*2+1].num+=T[x].flag;
	T[x*2].flag+=T[x].flag;
	T[x*2+1].flag+=T[x].flag;
	T[x].flag=0;
}
void insert(int x,int l,int r){
	if (T[x].l>r||l>T[x].r)return;
	if (T[x].l>=l&&T[x].r<=r){
		T[x].num++;
		T[x].flag++;
		return;
	}
	down(x);
	insert(x*2,l,r);
	insert(x*2+1,l,r);
}
int find(int x,int y){
	if (T[x].l==T[x].r)return T[x].num;
	down(x);
	int mid=(T[x].l+T[x].r)/2;
	if (y<=mid)return find(x*2,y);
	else return find(x*2+1,y);
}
int main(){
	scanf("%d%d",&m,&n);
	for (int i=1;i<=m;i++)scanf("%d%d",&A[i].l,&A[i].r);
	sort(A+1,A+m+1,cmp);
	build(1,1,n);
	for (int i=1,j=1;i<=n;i++){
		while (j<=m&&A[j].r-A[j].l+1<i){
			insert(1,A[j].l,A[j].r);
			j++;
		}
		int ans=m-j+1;
		for (int k=i;k<=n;k+=i)ans+=find(1,k);
		printf("%d\n",ans);
	}
	return 0;
}
