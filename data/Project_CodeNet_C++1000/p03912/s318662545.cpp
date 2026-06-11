#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> x(n);
	vector<int> mod(m);
	map<int,int> mp;
	rep(i,n){
		cin >> x[i];
		mod[x[i]%m]++;
		mp[x[i]]++;
	}
	vector<int> d(m);
	for (auto v: mp) {
		d[v.first%m] += v.second/2;
	}
	
	ll ans = 0;
	
	for (int i = 0; i+i <= m ; ++i) {
		if (i == 0) {
			ans += mod[i] / 2;
		} else if (i + i == m) {
			ans += mod[i] / 2;
		} else {
			int temp = min(mod[i], mod[m-i]);
			ans += temp;
			mod[i] -= temp;
			mod[m-i] -= temp;
		}
	}
	
	rep(i,m){
		if(i==0 || i+i==m) continue;
		int a = min(d[i], mod[i]/2);
		ans += a;
	}
	
	cout << ans << endl;
	
    return 0;
}