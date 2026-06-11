#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)

int main() {

	int n; cin >> n;
	int* a = new int[n];
	rep(i, 0, n) cin >> a[i];
	sort(a, a + n);

	// 一番でかい数字が直径

	// 直径が偶奇で別れる
	// 奇数の場合: 距離最小が2つ　(D + 1) / 2
	// 偶数の場合: 距離最小が1つ	D / 2
	vector<int> cnt(n, 0);
	int D = a[n - 1];
	rep(i, 0, n) ++cnt[a[i]];
	
	bool ok = cnt[D] > 1; // 端チェック
	ok &= cnt[(D + (D & 1)) / 2] == (D & 1) + 1; // 真ん中チェック
	rep(i, 0, (D + (D & 1)) / 2) ok &= cnt[i] == 0; // 距離が真ん中以下になることはない
	rep(i, (D + (D & 1)) / 2 + 1, D) ok &= cnt[i] > 1; // 2個以上あればつなげる？(木よくわからん)

	string ans = (ok ? "P" : "Imp");
	ans += "ossible";
	cout << ans << endl;

	return 0;
}