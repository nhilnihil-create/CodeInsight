#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	vector<int64_t> height(n);
	for (int i = 0; i < n; i++)cin >> height.at(i);
	vector<int64_t> height_copy = height;
	int64_t ans = 1000000000000000000;
	//処理 見たい建物をbitsetにしちゃうn-1^2.(一番左は無条件で見れる)→お金を出力
	for (int bit = 0; bit < (1 << n - 1); bit++) {
		vector<int> want(n, 0);
		want.at(0) = 1;
		for (int i = 0; i < n - 1; i++) {
			if (bit & (1 << i))want.at(i+1)++;
		}
		int ank = 0;
		for (int i = 0; i < n; i++)if (want.at(i)==1)ank++;
		if (ank != k)continue;
		int64_t res = 0;
		//処理
		int64_t high = height.at(0);
		for (int i = 1; i < n; i++) {
			if(want.at(i)){
				if (high < height.at(i))high = height.at(i);
				else {
					res += high - height.at(i) + 1;
					height.at(i) = high + 1;
					high++;
				}
			}
			else{
				if (high < height.at(i))high = height.at(i);
			}
		}
		if (ans > res)ans = res;
		height = height_copy;
	}
	cout << ans << endl;
}