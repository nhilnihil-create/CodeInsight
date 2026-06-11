#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;

void solve() {
	string s;
	ll l = 0, r = 0;
	cin >> s;
	for(int i = 0; i < s.size(); ++i) if(s[i] == 'A') {l = i;break;}
	for(int i = (int)s.size() - 1; i >= 0; --i) if(s[i] == 'Z') {r = i; break;}
	cout << r - l + 1 << endl;
	return;
}
	

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(35);
	solve();
	return 0;
}
