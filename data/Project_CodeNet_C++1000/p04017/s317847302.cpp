#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, l, q, ai, bi; 
int a[1000010];
int f[1000010][40];

void prepare() {
	for(int i = 1; i <= n; i++){
		int id = upper_bound(a + 1,a + 1 + n, a[i] + l) - a - 1;  
		if(a[i] + l > a[n])	f[i][0] = n;
		else f[i][0] = id;
	} 
	for(int i = 1; i <= 32; i++)
		for(int j = 1; j <= n; j++)
			f[j][i] = f[f[j][i - 1]][i - 1];
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) 
		scanf("%d", &a[i]);
	scanf("%d%d", &l, &q);
	prepare();
	while(q--) {
		scanf("%d%d", &ai, &bi);
		if(ai > bi) swap(ai, bi);
		int ans = 0;
		for(int j = 30; j >= 0; j --)  
			if(f[ai][j] < bi) { ans += (1 << j); ai = f[ai][j];}
		printf("%d\n", ans + 1);
	}
	return 0;
} 