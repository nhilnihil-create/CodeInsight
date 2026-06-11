#include <bits/stdc++.h>
using namespace std;

int n;
int a[200010];

bool check(int x){
	for (int l = n, r = n; l > 1; l--, r++){
		if ((a[l] >= x) == (a[l - 1] >= x)) return (a[l] >= x);
		if ((a[r] >= x) == (a[r + 1] >= x)) return (a[r] >= x);
	}
	return a[1] >= x;
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i < 2 * n; i++){
		scanf("%d", &a[i]);
	}
	int l = 1, r = 2 * n - 1;
	while (l < r){
		int mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l);
	return 0;
}
