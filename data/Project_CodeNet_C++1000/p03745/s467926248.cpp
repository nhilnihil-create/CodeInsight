#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	int n;
	int ans = 0;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < n; i++) {
		if (arr[i] == arr[i + 1] && i < n - 1) {
			continue;
		} else if (arr[i] > arr[i + 1]) {
			while (arr[i] >= arr[i + 1] && i < n - 1)
				i++;
		} else if (arr[i] < arr[i + 1]) {
			while (arr[i] <= arr[i + 1] && i < n - 1)
				i++;
		}
		ans++;
	}
	printf("%d\n", ans);
}
