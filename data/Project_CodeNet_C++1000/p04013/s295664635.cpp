#include <bits/stdc++.h>
#define maxn 55

using namespace std;

int n, a, x;
long long f[maxn][maxn][maxn * maxn], ans;

int main(){
	scanf("%d%d", &n, &a);
	f[0][0][0] = 1;
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		for(int j = 0;j <= i;j++){
			for(int k = 0;k < maxn * maxn;k++){
				f[i][j][k] = f[i - 1][j][k];
				if(j && k - x >= 0) f[i][j][k] += f[i - 1][j - 1][k - x];
			}
		}
	} 
	for(int i = 1;i <= n;i++) ans += f[n][i][i * a];
	printf("%lld", ans);
}