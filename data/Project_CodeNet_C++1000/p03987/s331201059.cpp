#include <bits/stdc++.h>
     
using namespace std;

int a[200000],reva[200001];


int main() {
	int n; cin >> n;
	for(int i=0;i<n;++i) cin>>a[i],reva[a[i]]=i;
	long long ans=0;
	set<int> lst,rst;
	lst.insert(1);
	rst.insert(n);
	for(int i=1;i<=n;++i) {
		auto lit=lst.lower_bound(-reva[i]);
		auto rit=rst.lower_bound(reva[i]);
		ans+=1LL*(reva[i]+*lit)*(*rit-reva[i])*i;
		lst.insert(-reva[i]); rst.insert(reva[i]);
	}
	cout << ans << endl;
	
	return 0;
}
