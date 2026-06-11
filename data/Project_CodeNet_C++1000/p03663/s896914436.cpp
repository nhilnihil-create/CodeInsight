#include <bits/stdc++.h>
using namespace std;


#define int long long 

int ask(int x) {
	cout << "? " << x << endl;
	fflush(stdout);
	string str; cin >> str;
	return str == "Y";
}

/*int ask(int x) {
	int k = 100;
	return ((x <= k && to_string(x) <= to_string(k)) ||
			(x > k && to_string(x) > to_string(k)));
}*/

int32_t main() {
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int len;
	for(int i = 10; i >= 0; i--) {
		if(ask((int)pow(10, i))) {
			len = i;
			break;
		}
	}

	if(len > 9) {
		int sum = 0;
		for(int i = 1; i <= 10; i++) {
			sum = sum * 10 + 9;
			if(ask(sum)) {
				len = i - 1;
				break;
			}
		}
		cout << "! " << (int)pow(10, len) << endl;
		fflush(stdout);
		return 0;
	}

	int l = (int)pow(10, len), r = (int)pow(10, len + 1) - 1;

	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(!ask(mid * 10)) l = mid;
		else r = mid - 1;
	}

	cout << "! " << l + 1 << endl;
	fflush(stdout);
}