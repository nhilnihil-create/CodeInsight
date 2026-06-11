#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
int arr[maxn];
ll suf[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	cin >> arr[1];
	for(int i=2;i<=n;i++) {
		char op;
		cin >> op >> arr[i];
		if(op == '-')	arr[i] *= -1;
	}
	for(int i=n;i>=1;i--)
		suf[i] = suf[i+1] + abs(arr[i]);
	ll ans = -1e18 , sum = 0;
	for(int i=1;i<=n;i++) {
		sum += arr[i];
		if(arr[i] < 0) {
			ll tem = 0;
			int j = i + 1;
			while(j <= n && arr[j] > 0)		tem += arr[j] , j++;
			ans = max(ans,sum - tem + suf[j]);
			sum += tem;
			i = j - 1;
		}
	}
	ans = max(ans,sum);
	cout << ans << endl;
	return 0;
}
