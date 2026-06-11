#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

bool cmp(int a, int b) {
	if (a % 10 != 0 && b % 10 != 0 && a % 10 != b % 10)
		return a % 10 < b % 10;
	else if (a % 10 == b % 10)
		return a < b;
	else
		return a % 10 > b % 10;

}
int main() {
	int n, ans = 0;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		ans += arr[i];
	}

	sort(arr, arr + n, cmp);

	int i = 0;
	while (ans % 10 == 0 && i < n) {
		ans -= arr[i];
		i++;
	}
	cout << ans << endl;

}
