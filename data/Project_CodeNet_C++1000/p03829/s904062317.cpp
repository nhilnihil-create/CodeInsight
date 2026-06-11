#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;

int main() {
	long long n,a,b;
	cin >> n >> a >> b;
	vector<long long> x(n);
	for(int i=0; i<n; i++){
		cin >> x.at(i);
	}
	long long ans = 0;
	for(int i=0; i<n-1; i++){
		ans += min((x.at(i+1)-x.at(i))*a, b);
	}
	cout << ans << endl;

}