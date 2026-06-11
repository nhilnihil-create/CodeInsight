#include <bits/stdc++.h>

using namespace std;

int main() {
	int n,m; cin >> n >> m;
	vector<int> cnt(n);
	while(m--) {
		int a,b; cin >> a >> b;
		++cnt[a-1],++cnt[b-1];
	}
	bool flag=true;
	for(int i=0;i<n;++i)
		if(cnt[i]&1) flag=false;
	cout << (flag?"YES":"NO") << endl;
	
	return 0;
}
