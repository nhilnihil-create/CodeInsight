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

	int n;
	cin>>n;
	vector<int> v(2*n);
	for(auto &x : v){
		cin>>x;
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans += v[i<<1];
	}
	cout<<ans<<endl;

	return 0;
}