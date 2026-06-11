#include<bits/stdc++.h>
using namespace std;
#define C getchar()
inline int read() {
	int num = 0;
	char c = C;
	for(;c<'0' || c>'9';c=C);
	for(;c>='0' && c<='9';c=C) num = (num << 1) + (num << 3) + c - 48;
	return num;
}

int n,k,q;
int a[110000];
int f[110000][25];

int main() {
	
	n = read();
	for(int i=1;i<=n;++i) a[i] = read();
	k = read(),q = read();
	a[n + 1] = 2e9;
	int now = 1;
	
	for(int i=1;i<=n;++i) {
		while (a[now] - a[i] <= k) ++ now;
		f[i][0] = now - 1;
	}
	
	for(int i=1;1<<i<=n;++i) {
		for(int j=n;j>=1;--j) { 
			f[j][i] = f[f[j][i - 1]][i - 1];
		}
	}
	
	for(int i=1;i<=q;++i) {
		int x = read(),y = read();
		if (x > y) swap(x , y);
		int j = 20,ans = 0;
		for(;1 << j > n;--j);
		
		for(;j>=0;--j) while (f[x][j] < y) x = f[x][j],ans += 1 << j;
		printf("%d\n",ans + 1);
	}
	
	return 0;
} 