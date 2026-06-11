#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int ans = 1;
	sort(arr, arr + n);
	if (arr[n - 1] - arr[0] <= 2) {
		return printf("%d\n", n), 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (arr[j] - arr[i] > 2) {
				ans = max(ans, j - i);
				break;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
