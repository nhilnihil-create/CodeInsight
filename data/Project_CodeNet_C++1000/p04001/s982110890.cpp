#include <iostream>
#include <bitset>
#include <math.h>
using namespace std;

int main() {
	string str;
	cin >> str;
	long long ans = 0, tmp;
	for (int i = 0;i < pow(2,str.size()-1);i++) {
		bitset<9> s(i);

		tmp = str[0] - '0';
		for (int j = 0;j < str.size()-1;j++) {
			if (s.test(j)) {
				ans += tmp;
				tmp = str[j + 1] - '0';
			}
			else {
				tmp *= 10;
				tmp += str[j + 1] - '0';
			}
		}
		ans += tmp;
	}

	cout << ans << endl;

	return 0;
}