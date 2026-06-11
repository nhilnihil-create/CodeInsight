#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

using namespace std;

int n;
int a[333][333];
long long an;

int main(){
//	freopen("input.inp", "r", stdin);
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			for(int k = 1; k <= n; ++k){
				if (a[i][j] + a[j][k] < a[i][k]){
					printf("-1");
					return 0;
				}
			}
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			bool ok = 1;
			for(int k = 1; k <= n; ++k) if (k != i && k != j){
				if (a[i][k] + a[k][j] == a[i][j]){
					ok = 0;
					break;
				}
			}
			if (ok) an += a[i][j];
		}
	}	
	printf("%lld",an / 2);
	return 0;
}