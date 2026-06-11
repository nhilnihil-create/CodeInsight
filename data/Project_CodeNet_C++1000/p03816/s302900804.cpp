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

	int n; cin>>n;
	map<int, int> mp;
	for(int i = 1; i <= n; i++){
		int x; cin>>x; mp[x]++;
		if(mp[x] == 3)mp[x] -= 2;
	}
	int ans = mp.size();
	int cnt = 0;
	for(auto x : mp){
		if(x.second == 2)cnt++;
	}
	ans -= (cnt&1);
	cout<<ans<<'\n';

	return 0;
}