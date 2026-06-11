#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 250010
using namespace std;
struct bb{int x, id;}b[510];
int n, x, a[N], sum[510], now, now1;
inline bool cmp(bb a, bb b){return a.x<b.x;}
int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++){scanf("%d", &x); b[i].x=x; b[i].id=i;}
	sort(b+1, b+1+n, cmp);
	memset(a, 0, sizeof(a)); memset(sum, 0, sizeof(sum));
	for(int i=1; i<=n; i++){a[b[i].x]=b[i].id; sum[b[i].id]++;}
	now=1; if(b[1].id==1)now++;
	now1=1;
	for(int i=1; i<=n*n; i++){
		if(a[i]){if(sum[a[i]]!=a[i]){printf("No"); return 0;} continue;}
		if(now<=n){
			a[i]=b[now].id; sum[b[now].id]++;
			while(now<=n&&sum[b[now].id]==b[now].id)now++;
		}else{
			while(sum[b[now1].id]==n)now1++;
			a[i]=b[now1].id; sum[b[now1].id]++;
		}
	}
	printf("Yes\n");
	for(int i=1; i<=n*n-1; i++)printf("%d ", a[i]); printf("%d", a[n*n]);
	return 0;
}