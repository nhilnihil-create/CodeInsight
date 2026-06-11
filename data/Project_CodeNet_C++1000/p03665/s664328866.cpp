#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long
int arr[60];
int n, p;

int main() {

	scanf("%d%d", &n, &p);
	ll ans = 0, odd = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] & 1)
			odd++;
	}
	ans = (odd == 0 ? ((p == 1) ? 0 :( 1LL << n)) : (1LL << (n-1)));
	cout << ans;
}
