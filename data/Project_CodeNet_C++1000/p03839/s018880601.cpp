#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ll long long
#define pi pair<int, int>
#define f first
#define s second

const int mxn = 100002;
int n, k;
ll a[mxn];
ll s[2][mxn];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int t = 0; t < 2; t++){
		for(int i = 1; i <= n; i++){
			s[t][i] = max(0ll, a[i]) + s[t][i - 1];
		}
		reverse(a, a + n + 2);
	}
	reverse(s[1], s[1] + n + 2);
	
	for(int i = 1; i <= n; i++) a[i] += a[i - 1];
	
	ll ret = 0xcfcfcfcfcfcfcfcf;
	for(int i = 1; i <= n - k + 1; i++){
		ret = max(ret, s[0][i - 1] + s[1][i + k] + max(0ll, a[i + k - 1] - a[i - 1]));
	}
	
	cout << ret << endl;

	return 0;
}