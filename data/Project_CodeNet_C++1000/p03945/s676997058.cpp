#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
#include<sstream>
using namespace std;

// 特定の文字列を数える関数
size_t count(const string& str, const string& sub, const size_t ini = 0, const size_t fin = string::npos) {
	size_t pos = str.find(sub, ini);
	size_t cnt = 0;
	while (pos < fin) {
		cnt += 1;
		pos = str.find(sub, pos + sub.length());
	}
	return cnt;
}

int main() {

	string S;
	cin >> S;

	string ns = S.substr(0, 1);
	for (int i = 1; i < S.length(); i++) {
		if (ns.back() == S[i]) {
			continue;
		}
		else {
			ns += S.substr(i, 1);
		}
	}

	if (ns.length() > 1) {
		int cnt = 0;

		string str = ns.substr(0, 2);

		cnt = count(ns, str);

		cnt = 2 * cnt - 1;

		if (ns.length() % 2 == 1) {
			cnt += 1;
		}

		cout << cnt << endl;
	}
	else {
		cout << 0 << endl;
	}
	

	return 0;
}