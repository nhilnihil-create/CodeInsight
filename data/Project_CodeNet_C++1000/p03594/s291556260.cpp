#include<bits/stdc++.h>
using namespace std;
int n,m,K;
char a[1010][1010];
int main() {
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=m;++j) {
			int x=(i+j)-1, y=(i-j)-(1-m)+1;
			int s=((x-1)/K+1)&1, t=((y-1)/K+1)&1;
			if(!s && !t) putchar('R');
			if(!s && t) putchar('G');
			if(s && !t) putchar('B');
			if(s && t) putchar('Y');
		}
		puts("");
	}
	return 0;
}