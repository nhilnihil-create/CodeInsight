#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//  2進数ならば baseNumber を  2 とする
// 10進数ならば baseNumber を 10 とする
int GetDigitsCount(int targetNumber, int baseNumber=10) {
	int digitsCount = 0;
	while (targetNumber != 0) {
		digitsCount++;
		targetNumber /= baseNumber;
	}
	return digitsCount;
}


int main() {
	
	int n, k; cin >> n >> k;
	//int digit_n = GetDigitsCount(n);
	const int p = 10;
	vector<bool> canUse(p, true);
	for (int i = 0; i < k; i++) {
		int d; cin >> d;
		canUse[d] = false;
	}
	//int canUseMinValue = 1;
	//while (true) {
	//	if (!canUse[canUseMinValue]) {
	//		canUseMinValue--;
	//		break;
	//	}
	//}
	int ans;
	//int start = 10 * (digit_n - 1);
	//int end = 10 * (digit_n - 1) * canUseMinValue;
	//for (int i = start; i <= end; i++) {
	//	if (i < n) continue;
	//	string i_string = to_string(i);
	//	for (int j = 0; j < i_string.size(); j++) {
	//		if (!canUse[(i_string[j] - '0')]) {
	//			continue;
	//		}
	//	}
	//	ans = i;
	//	break;
	//}
	int now = n;
	while (true) {
		string now_s = to_string(now);
		bool ok = true;
		for (int i = 0; i < now_s.size(); i++) {
			for (int j = 0; j < p; j++) {
				if (!canUse[(int)(now_s[i] - '0')]) {
					ok = false;
					break;
				}
			}
		}
		if (ok) {
			ans = now;
			break;
		}
		now++;
	}
	cout << ans << endl;
	return 0;
}