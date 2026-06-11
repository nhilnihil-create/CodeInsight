#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N];

int main(){
	int n;
	long long sum, tot;
	scanf("%d",&n);
	sum = 0;
	for (int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
		sum += a[i];
	}
	if (n == 1){
		printf("YES\n");
		return 0;
	}
	if (sum % (1LL * n * (n + 1) / 2)){
		printf("NO\n");
		return 0;
	}
	tot = sum / (1LL * n * (n + 1) / 2);
	if (tot + a[n] - a[1] < 0 || (tot + a[n] - a[1]) % n > 0){
		printf("NO\n");
		return 0;
	}
	for (int i = 1; i < n; i++){
		if (tot + a[i] - a[i + 1] < 0 || (tot + a[i] - a[i + 1]) % n > 0){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}