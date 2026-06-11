#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for (int (i) = 1; (i) <= (n); (i++))
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define yn {puts("Yes");}else {puts("No");}
#define printd(x) printf("%.12f\n", ans);
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
	int h, w;
	cin >> h >> w;
	string a[h];
	rep (i, h) cin >> a[i];

	int mp[26] = {};
	rep (i, h) rep (j, w) mp[a[i][j] - 'a']++;

	int cnt2 = 0, cnt4 = 0, cnt1 = 0;
	rep (i, 26) {
		if (mp[i] >= 4) {
			cnt4 += mp[i] / 4;
			mp[i] -= mp[i] / 4 * 4;
		}
		if (mp[i] >= 2) {
			cnt2 += mp[i] / 2;
			mp[i] -= mp[i] / 2 * 2;
		}
		if (mp[i] >= 1) cnt1++;
	}

	int need4 = (h / 2 * 2) * (w / 2 * 2);
	if (cnt4 * 4 >= need4 && cnt1 == (h % 2 && w % 2)) yn

	return 0;
}