#include <bits/stdc++.h>

using namespace std;

int main() {
	int n,k; cin >> n >> k;
	vector<long long> t1(n+1),t2(n+1);
	for(int i=1;i<=n;++i) {
		long long a; cin >> a;
		t1[i]=t1[i-1]+a;
		t2[i]=t2[i-1]+(a>0?a:0);
	}
	long long ans=0;
	for(int i=k;i<=n;++i) {
		long long tmp=t1[i]-t1[i-k];
		if(tmp<0) tmp=0;
		ans=max(ans,t2[n]-(t2[i]-t2[i-k])+tmp);
	}
	cout << ans << endl;
	
	return 0;
}