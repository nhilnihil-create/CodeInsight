#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <queue>
using namespace std;
#define N 150
#define GG puts("Impossible");return 0
int n,a[N],c[N],mx;
int main() {
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++) scanf("%d",&a[i]),c[a[i]]++,mx=max(mx,a[i]);
	if(c[mx]<2) {GG;}
	for(i=2;i<=mx;i++) {
		int t=max(i-1,mx-i+1);
		if(!c[t]) {GG;}
		c[t]--;
	}
	for(i=1;i<mx;i++) if(c[i]) {
		int flg=0;
		for(j=2;j<=mx;j++) {
			int t=max(j-1,mx-j+1)+1;
			if(t==i) {flg=1; break;}
		}
		if(!flg) {GG;}
	}
	puts("Possible");
}
