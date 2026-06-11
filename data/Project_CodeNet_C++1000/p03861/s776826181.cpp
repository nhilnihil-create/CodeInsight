#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a, b, x;

void solve()
{
	ll st= a/x;
	if(a%x) st++;
	ll ed = b/x;
	if(ed<st) cout<<0<<'\n';
	else cout<<ed-st+1<<'\n';
}

int main()
{
	cin >> a >> b >> x;
	solve();
	return 0;
}