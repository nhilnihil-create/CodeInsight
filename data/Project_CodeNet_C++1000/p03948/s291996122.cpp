#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int arr[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,T;
	cin >> n >> T;
	for(int i=1;i<=n;i++)
		cin >> arr[i];
	int max_val = arr[n] , max_dif = 0;
	int ans = 0;
	for(int i=n-1;i>=1;i--) {
		if(max_val - arr[i] > max_dif) {
			ans = 1;
			max_dif = max_val - arr[i];
		}
		else if(max_val - arr[i] == max_dif) {
			ans++;
		}
		max_val = max(max_val,arr[i]);
	}
	cout << ans << endl;
	return 0;
}
