#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, l, q;
int a[maxn];
int f[maxn][25];
int x, y;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	scanf("%d%d", &l, &q);
	f[n][0] = n;
	for(int i = n - 1;i;i--){
		f[i][0] = f[i + 1][0];
		while(a[f[i][0]] - a[i] > l) f[i][0]--;
	}
	for(int j = 1;j <= 20;j++) for(int i = 1;i <= n;i++) f[i][j] = f[f[i][j - 1]][j - 1];
	while(q--){
		scanf("%d%d", &x, &y);
		if(x > y) swap(x, y);
		int ans = 0;
		for(int i = 20;~i;i--){
			if(f[x][i] < y) ans += 1 << i, x = f[x][i];
		}
		printf("%d\n", ans + 1);
	}
}