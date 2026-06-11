#include <bits/stdc++.h>
     
using namespace std;

#define MOD 1000000007

int main() {
	int n; cin >> n;
	vector<int> t(n),a(n);
	for(auto&e:t) cin >> e;
	for(auto&e:a) cin >> e;
	vector<bool> used(n);
	used[0]=used[n-1]=true;
	bool miss=false;
	for(int i=1;i<n;++i) {
		if(t[i-1]<t[i]) {
			used[i]=true;
			if(a[i]<t[i]) miss=true;
		}
		if(t[i-1]>t[i]) miss=true;
	}
	for(int i=n-2;i>=0;--i) {
		if(a[i+1]<a[i]) {
			used[i]=true;
			if(t[i]<a[i]) miss=true;
		}
		if(a[i+1]>a[i]) miss=true;
	}
	if(miss||t[n-1]!=a[0]) {
		cout << 0 << endl;
		return 0;
	}
	long long ans=1;
	for(int i=0;i<n;++i)
		if(!used[i]) (ans*=min(t[i],a[i]))%=MOD;
	cout << ans << endl;
	
	return 0;
}
