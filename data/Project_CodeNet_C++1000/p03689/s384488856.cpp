#include <bits/stdc++.h>

const int N=510;

int H,W,h,w,mp[N][N];

void Init() {
	scanf("%d%d%d%d",&H,&W,&h,&w);	
}

void Work(int H,int W,int h,int w) {
	int v=-H/h/(H%h)-1;
	for (int i=0;i<H;++i) {
		if (i%h==h-1) for (int j=0;j<W;++j) mp[i][j]=v*(h-1)-1;
		else for (int j=0;j<W;++j) mp[i][j]=-v;
	}
}

void Solve() {
	if (H%h) {
		printf("Yes\n");
		Work(H,W,h,w);
		for (int i=0;i<H;++i) {
			for (int j=0;j<W;++j) printf("%d%c",mp[i][j],j==W-1?'\n':' ');		
		}
	}else if (W%w) {
		printf("Yes\n");
		Work(W,H,w,h);
		for (int j=0;j<H;++j) {
			for (int i=0;i<W;++i) printf("%d%c",mp[i][j],i==W-1?'\n':' ');
		}
	}else printf("No\n");
}

int main() {
	Init();
	Solve();
	return 0;
}