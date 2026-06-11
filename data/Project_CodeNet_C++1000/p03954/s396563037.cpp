#include <bits/stdc++.h>
using namespace std;

int a[200010];
int b[200010];
int n;

int check(int mid){
	for (int i = 0; i < 2 * n - 1; i++){
		b[i] = a[i] >= mid;
	}
	for (int i = n - 1; i >= 1; i--){
		int j = 2 * (n - 1) - i;
		if (b[i] == b[i - 1] || b[j] == b[j + 1]) return b[i];
	}
	return b[0];
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < 2 * n - 1; i++){
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
