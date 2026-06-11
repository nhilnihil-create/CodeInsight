#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int N=300005;

struct node{
	int x,w;
}a[N];
int n,cnt,m,now,pos;
int pre[N],nxt[N],b[N],tot[N],p[N];

bool cmp(node a,node b){
	return a.x<b.x;
}

void del(int k){
	pre[nxt[k]]=pre[k];
	nxt[pre[k]]=nxt[k];
}

int main(){
	int i,j;
	scanf("%d",&n); m=n*n;
	for (i=1;i<=n;i++) scanf("%d",&a[i].x),a[i].w=i;
	sort(a+1,a+1+n,cmp);
	for (i=1;i<=m;i++) pre[i]=i-1,nxt[i]=i+1;
	pre[m+1]=m; nxt[0]=1;
	for (i=1;i<=n;i++){
		if (b[a[i].x]){
			printf("No\n");
			return 0;
		}
		b[a[i].x]=a[i].w; del(a[i].x);
		for (j=nxt[0],cnt=1;j<=m;j=nxt[j]){
			if (cnt==a[i].w) break;
			if (j>a[i].x){
				printf("No\n");
				return 0;
			}
			b[j]=a[i].w; del(j);
			cnt++;
		}
	}
	now=a[1].w; pos=1;
	for (i=1;i<=n;i++) tot[i]=i;
	for (i=1;i<=n;i++) p[a[i].w]=a[i].x;
	if (tot[now]==n) now=a[++pos].w;
	for (i=nxt[0];i<=n*n;i=nxt[i])
		if (!b[i]){
			if (i<p[now]){
				printf("No\n");
				return 0;
			}
			p[now]=i; tot[now]++;
			b[i]=now;
			while (tot[now]==n) now=a[++pos].w;
		}
	printf("Yes\n");
	for (i=1;i<=n*n;i++) printf("%d ",b[i]); 
	return 0;
}
/*
4
1 5 10 8
*/