#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

int n, m;

int main(void){
	cin >> n >> m;
	vector<int> ans(n);
	rep(i, m){
		int a, b;
		cin >> a >> b;
		ans[a-1]++;
		ans[b-1]++;
	}
	rep(i, n) cout << ans[i] << endl;
	return 0;
}
