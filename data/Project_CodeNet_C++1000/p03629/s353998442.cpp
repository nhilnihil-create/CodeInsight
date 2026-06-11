#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 200500, mod = 998244353;
string s;
int n, cnt[26], z, suf[maxn];
int getlen() {
	memset(cnt, 0, sizeof cnt), z = 26;
	int ans = 1;
	for(int i = n; i--;) {
		if(cnt[s[i]-'a']++ == 0) z--;
		if(z == 0) {
		memset(cnt, 0, sizeof cnt), z = 26;
			ans++;
		}
		suf[i] = ans;
	}
	return ans;
}
vi pos[26];
void purge(int x) {
	for(auto &i : pos) {
		while(!i.empty()&&i.back()<=x) i.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s, n = s.size();
	int len = getlen();
	for(int i = n; i--;) pos[s[i]-'a'].pb(i);
	string ans(len, ' ');
	for(int i = 0; i < len; i++) {
		for(int j = 0; j < 26; j++) {
			if(!pos[j].empty()&&suf[1+pos[j].back()]>=len-i) continue;
			ans[i] = 'a'+j;
			if(!pos[j].empty()) purge(pos[j].back());
			break;
		}
	}
	cout << ans;
}
