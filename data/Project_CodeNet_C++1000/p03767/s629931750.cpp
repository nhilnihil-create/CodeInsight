#include <bits/stdc++.h>
using namespace std;

int a[300100];

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < 3*n; i++)
		scanf("%d", a+i);
	sort(a, a + 3*n, greater<int>());
	long ans = 0;
	for(int i = 1; i < 2*n; i+=2)
		ans += a[i];
	printf("%ld\n", ans);
}
