#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 110
using namespace std;
int n, m, m1, sum, s, a[N], b[N];
int main(){
	scanf("%d%d", &n, &m);
	for(int i=1; i<=m; i++)scanf("%d", &a[i]);
	sum=0; for(int i=1; i<=m; i++)if(a[i]&1)sum++;
	if(sum>=3){printf("Impossible"); return 0;}
	for(int i=2; i<=m; i++)if(a[i]&1){
		if(a[1]&1)swap(a[i], a[m]); else swap(a[i], a[1]);
	}
	for(int i=1; i<=m; i++)b[i]=a[i];
	if(m==1){m1=2; b[1]--; b[2]=1;}
	else{m1=m; b[1]--; b[m1]++;}
	s=0; for(int i=1; i<=m1; i++)if(b[i])b[++s]=b[i];
	for(int i=1; i<=m-1; i++)printf("%d ", a[i]); printf("%d\n", a[m]);
	printf("%d\n", s);
	for(int i=1; i<=s-1; i++)printf("%d ", b[i]); printf("%d\n", b[s]);
	return 0;
}