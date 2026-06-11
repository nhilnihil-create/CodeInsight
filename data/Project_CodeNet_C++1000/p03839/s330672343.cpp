#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 1e5 + 5;

int n, k;
ll sol, sum;
ll a[maxn];
ll b[maxn];

int main(){
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++) b[i] = b[i - 1] + a[i];
	
	for(int i = k + 1; i <= n; i++) sum += max(0LL, a[i]);
	
	for(int i = 1; i <= n - k + 1; i++){
		ll x = sum + max(0LL, b[i + k - 1] - b[i - 1]);
		
		sol = max(sol, x);
		
		sum += max(0LL, a[i]);
		
		sum -= max(0LL, a[i + k]);
	}
	
	cout << sol;
	
	return 0;
}