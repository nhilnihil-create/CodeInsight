#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
struct node {
	int l,r;
	int operator<(const node &a) {
		return r-l<a.r-a.l;
	}
}a[maxn];
int c[maxn],n,m;
void add(int x,int v) {
	for(int i=x;i<=n;i+=i&-i)c[i]+=v;
}
int qry(int x) {
	int sum=0;
	for(int i=x;i;i-=i&-i)sum+=c[i];
	return sum;
}
int main() {
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&a[i].l,&a[i].r);
	sort(a+1,a+m+1);
	for(int i=1,j=1;i<=n;i++) {
		while(j<=m&&a[j].r-a[j].l+1<i) {
			add(a[j].l,1);
			add(a[j].r+1,-1);
			j++;
		}
		int ans=m-j+1;
		for(int j=i;j<=n;j+=i)ans+=qry(j);
		printf("%d\n",ans);
	}
	return 0;
}