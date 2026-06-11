#include <iostream>

using namespace std;
//前缀和
int main() {

	int n;
	scanf("%d", &n);

//	int a[n];
	long long prefix[n + 1];

//	scanf("%d", &a[0]);
//	prefix[0] = a[0];
	prefix[0] = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &prefix[i]);
		prefix[i] += prefix[i - 1];
	}

	long long min = abs(2 * prefix[1] - prefix[n]);
	long long temp;
	for (int i = 2; i < n; ++i) {
		temp = abs(2 * prefix[i] - prefix[n]);
		min = min < temp ? min : temp;
	}

	printf("%lld", min);


	return 0;
}