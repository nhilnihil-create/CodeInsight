#include <bits/stdc++.h>
using namespace std;

int a[105], cnt[105];

int main(){
	int n, maxx, minx;
	scanf("%d",&n);
	memset(cnt, 0, sizeof(cnt));
	minx = 1000; maxx = 0;
	for (int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
		maxx = max(maxx, a[i]);
		minx = min(minx, a[i]);
	}
	if (maxx & 1){
		if (minx != maxx / 2 + 1 || cnt[minx] != 2){
			printf("Impossible\n");
			return 0;
		}
	}
	else{
		if (minx != maxx / 2 || cnt[minx] != 1){
			printf("Impossible\n");
			return 0;
		}
	}
	for (int i = minx + 1; i <= maxx; i++){
		if (cnt[i] < 2){
			printf("Impossible\n");
			return 0;
		}
	}
	printf("Possible\n");
	return 0;
}