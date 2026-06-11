#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int H, W; cin >> H >> W;
	map<char, int> mp;
	rep(i, H*W) {
		char x;
		cin >> x;
		mp[x]++;
	}
	// 回文を構成するために4つ必要な英字の数
	int square = (H/2) * (W/2);
	// HもWも奇数であれば、最後に英字1つが残っている必要がある
	bool odd = (H%2!=0 && W%2!=0) ? true : false;

	int sq_cnt = 0, odd_cnt = 0;
	for(const auto& m: mp) {
		if (m.second%2==1) odd_cnt++;
		sq_cnt += m.second/4;
	}

	if ((sq_cnt>=square) && ((odd&&odd_cnt==1) || (!odd&&!odd_cnt))) puts("Yes");
	else puts("No");
}