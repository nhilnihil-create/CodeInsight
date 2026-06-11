#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n; ll a, b;
	cin>>n>>a>>b;
	vector<int> x(n);
	for(int i = 0; i < n; i++){
		cin>>x[i];
	}
	ll ans = 0;
	for(int i = 1; i < n; i++){
		ans += min(a*(x[i] - x[i - 1]), b);
	}
	cout<<ans<<'\n';

	return 0;
}