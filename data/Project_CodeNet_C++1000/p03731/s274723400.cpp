#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 200009;
int N, T;
ll t[MAX_N];

void solve()
{
	ll ans = 0;
	ll b=0, e=T;
	for(int i=1;i<N;++i){
		if(t[i]<=e) e=max(e,t[i]+T);
		else{
			ans += e-b;
			b=t[i], e=t[i]+T;
		}
	}
	ans += e-b;
	cout << ans << '\n';
}

int main()
{
	cin >> N >> T;
	for(int i=0;i<N;++i) cin >> t[i];
	solve();
	return 0;
}