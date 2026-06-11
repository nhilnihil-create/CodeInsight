#include <bits/stdc++.h>
using namespace std;

char s[100010];
int a[100010], p[100010];

int main(){
	int n; scanf("%d%s", &n, s);
	for (int i = 0; i < n; i++){
		p[i] = s[i] == 'x';
	}
	p[n] = p[0];
	for (a[0] = 0; a[0] < 2; a[0]++){
		for (a[1] = 0; a[1] < 2; a[1]++){
			for (int i = 2; i <= n + 1; i++){
				a[i] = a[i - 2] ^ (p[i - 1] ^ a[i - 1]);
			}
			if (a[n] == a[0] && a[n + 1] == a[1]){
				for (int i = 0; i < n; i++){
					printf(a[i] ? "W" : "S");
				}
				printf("\n");
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}
