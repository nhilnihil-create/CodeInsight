#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
int ans = 1;
inline ll inverse(int x){ return pow(x, mod - 2); }
inline int get(std::string s) {
	int x = 0;
	for(char i : s) x = x * 10 + (i & 15);
	return x;
}
inline bool chk(std::string s) {
	cout << "? " << s << std::endl;
	cin >> s;
	return s == "Y";
#ifdef ONLINE_JUDGE
#else
	std::cerr << "debug : ask : " << s << std::endl;
	return get(s) <= ans && s <= std::to_string(ans) || get(s) > ans && s > std::to_string(ans);
#endif
}
inline int getlen() {
	for(int len = 1;len <= 10;++len) {
		if(!chk("1" + std::string(len - 1, '0'))) {
			return len - 1;
		}
	}
	for(int len = 9;len >= 1;--len) {
		if(!chk(std::string(len, '9'))) {
			cout << "! " << 1 << std::string(len, '0') << '\n';
			exit(0);
		}
	}
	cout << "! " << 1 << '\n';
	exit(0);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int len = getlen();
	std::string s;
	for(int i = 1;i < len;++i) {
		int l = 0, r = 10;
		for(;l + 1 != r;) {
			int mid = l + r >> 1;
			if(chk(s + char(mid + '0'))) {
				l = mid;
			} else {
				r = mid;
			}
		}
		s += char(l + '0');
	}
	for(int i = 8;i >= -1;--i) {
		if(i < 0 || !chk(s + char(i + '0') + char(i + '0'))) {
			cout << "! " << s << i + 1 << '\n';
			return 0;
		}
	}
}
