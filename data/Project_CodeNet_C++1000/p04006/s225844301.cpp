#include <bits/stdc++.h>
     
using namespace std;

int main() {
	long long n,x; cin >> n >> x;
	vector<long long> a(n);
	for(auto&e:a) cin >> e;
	vector<long long> b(a);
	long long ans=1e18;
	for(int i=0;i<n;++i) {
		long long tmp=0;
		for(int j=0;j<n;++j) tmp+=b[j]=min(b[j],a[(j-i+n)%n]);
		ans=min(ans,tmp+x*i);
	}
	cout << ans << endl;
	
	return 0;
}
