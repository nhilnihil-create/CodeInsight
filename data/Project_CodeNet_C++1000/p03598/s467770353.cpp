#include <bits/stdc++.h>

using namespace std;
#define NIL -1
#define ll long long
#define MAX 100
#define pb push_back

int main()
{
	int n, k;
	cin >> n >> k;
	ll ans = 0;
	int arr[n];
	for(int i=0; i<n; i++) cin >> arr[i];
	for(int i=0; i<n; i++) {
		int temp = min(arr[i], k-arr[i]);
		ans += temp;
	}
	cout << ans *2 << endl;
	return 0;
}
