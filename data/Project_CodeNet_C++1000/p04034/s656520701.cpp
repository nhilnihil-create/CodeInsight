#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n, m;

int main(void){
	cin >> n >> m;
	vector<lli> a(n+1, 1);
	vector<bool> ans(n+1);
	ans[1] = true;
	rep(k, m){
		lli x, y;
		cin >> x >> y;
		if(ans[x]){
			if(a[x] < 2){
				ans[x] = false;
			}
			ans[y] = true;
		}
		a[x]--;
		a[y]++;
	}
	lli ret = 0;
	for(int i = 1; i <= n; i++) if(ans[i]) ret++;
	cout << ret << endl;
	return 0;
}
