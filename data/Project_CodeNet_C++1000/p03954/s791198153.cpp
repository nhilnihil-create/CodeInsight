#include <bits/stdc++.h>

using namespace std;

#define N 100000

int n;
int a[2*N+5];

int check(int x) {
	for(int i = 0; i < n-1; ++i) {
		if((a[n-i] <= x && a[n-i-1] <= x) || (a[n+i] <= x && a[n+i+1] <= x)) return 1;
		else if((a[n-i] > x && a[n-i-1] > x) || (a[n+i] > x && a[n+i+1] > x)) return 0;
	}
	return a[1] <= x;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= 2*n-1; ++i) scanf("%d", &a[i]);
	int l = 1, r = 2*n-1;
	while(l != r) {
		int mid = l+r>>1;
		if(check(mid)) r = mid;
		else l = mid+1;
	}
	printf("%d\n", r);
	return 0;
}