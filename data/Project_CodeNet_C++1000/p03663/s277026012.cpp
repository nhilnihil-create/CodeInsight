#include <iostream>
#include <vector>
#include <cassert>
#define int long long
using namespace std;

int getKetasu0() {
	int beet = 1, i;
	for (i = 0; ; i++) {
		cout << "? " << beet << endl;
		cout.flush();
		char latte;
		cin >> latte;
		if (latte == 'N') break;
		beet *= 10;
	}
	return i;
}

int getKetasu9() {
	int beet = 1, usi = 0, i;
	for (i = 0; ; i++) {
		usi += beet * 9;
		beet *= 10;
		cout << "? " << usi << endl;
		cout.flush();
		char latte;
		cin >> latte;
		if (latte == 'Y') break;
	}
	return i + 1;
}

signed main() {
	int p10[11], i;
	p10[0] = 1;
	for (i = 1; i < 11; i++) p10[i] = p10[i - 1] * 10;
	
	//答えが10^nの形かを判定
	cout << "? " << p10[10] << endl;
	cout.flush();
	char res;
	cin >> res;
	if (res == 'Y') {
		int ketasu = getKetasu9();
		cout << "! " << p10[ketasu - 1] << endl;
		return 0;
	}
	
	//答えは10^nの形ではない
	int ketasu = getKetasu0();
	int ans = 0;
	
	//1. 先頭桁が1かどうかを判定する
	bool sento = false;
	cout << "? " << 19999999999 << endl;
	char tokura;
	cin >> tokura;
	if (tokura == 'Y') { sento = true; }
	ans += sento;
	
	//残り桁
	for (i = sento; i < ketasu; i++) {
		int st = -1, ed = 9, mid;	//(st, ed]
		while (ed - st >= 2) {
			mid = (st + ed) / 2;
			cout << "? " << (ans * 10 + mid) * p10[10 - i] + p10[10 - i] - 1 << endl;
			cout.flush();
			char kuti;
			cin >> kuti;
			if (kuti == 'Y') ed = mid;
			else st = mid;
		}
		ans *= 10;
		ans += ed;
	}
	cout << "! " << ans << endl;
	cout.flush();
	return 0;
}