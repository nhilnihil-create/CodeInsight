#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
long long f[maxn][3];
int x;
char s[maxn];

int main(){
	memset(f, -0x3f, sizeof(f));
	scanf("%d", &n);
	scanf("%d", &x);
	f[1][0] = x;
	for(int i = 2;i <= n;i++){
		scanf("%s%d", s, &x);
		if(s[0] == '-'){
			for(int j = 0;j < 3;j++) f[i][j] = max(f[i][j], f[i - 1][j] + x * (j & 1 ? 1 : -1));
			for(int j = 0;j < 2;j++) f[i][j + 1] = max(f[i][j + 1], f[i - 1][j] + x * (j & 1 ? 1 : -1));
		}else{
			for(int j = 0;j < 3;j++) f[i][j] = max(f[i][j], f[i - 1][j] + x * (j & 1 ? -1 : 1));
		}
		f[i][0] = max(f[i][0], f[i][1]);
		f[i][1] = max(f[i][1], f[i][2]);
	}
	printf("%lld", f[n][0]);
}