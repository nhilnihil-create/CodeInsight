#include <bits/stdc++.h>

using namespace std;

int sg[200][200];
typedef long long LL;

int main() {
	LL x,y;
	scanf("%lld%lld",&x,&y);
	puts(abs(x-y)<=1?"Brown":"Alice");
	/*
	sg[0][0] = 0;
	for (int s=1;s<=40;s++) {
		for (int i=0;i<=s;i++) {
			int j = s - i;
			sg[i][j] = 0;
			for (int k=1;k<=i/2;k++) {
				sg[i][j] |= (sg[i-k*2][j+k] == 0);
			}
			for (int k=1;k<=j/2;k++) {
				sg[i][j] |= (sg[i+k][j-k*2] == 0);
			}
		}
	}
	for (int i=0;i<=15;i++) {
		for (int j=0;j<=15;j++) {
			printf("%d",sg[i][j]);
		}
		puts("");
	}
	*/
}