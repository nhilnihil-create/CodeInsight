#include <bits/stdc++.h>
using namespace std;
const int mn=510;
int n,m,d,id[mn][mn];
int d1[mn][mn],d2[mn][mn];
bool ok(int a) {
	return 1<=a%(2*d)&&a%(2*d)<=d;
}
int main() {
	scanf("%d %d %d",&n,&m,&d);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			d1[i][j]=i+j-1;
			d2[i][j]=n-(i-j);
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			if (ok(d1[i][j])&&ok(d2[i][j]))
				printf("G");
			else if (ok(d1[i][j])&&!ok(d2[i][j]))
				printf("R");
			else if (!ok(d1[i][j])&&ok(d2[i][j]))
				printf("Y");
			else printf("B");
		}
		printf("\n");
	}
	return 0;
}