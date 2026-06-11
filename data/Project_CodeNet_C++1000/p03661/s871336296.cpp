#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> a;
long long ans = 1e18+9;

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=0; i<n; ++i){
		long long t;
		cin >> t;
		a.push_back(t);
	}
	for(int i=1; i<n; ++i)
		a[i] += a[i-1];
	for(int i=0; i<n-1; ++i)
		ans = min(ans, abs(a[i] - (a[n-1] - a[i])));
	cout << ans << "\n";
}