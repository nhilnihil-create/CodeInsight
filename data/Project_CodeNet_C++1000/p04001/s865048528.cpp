#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;

	int s_len = s.length();
	int b_n = s_len - 1;
	long long answer = 0;
	for (int bit = 0; bit < (1 << b_n); ++bit) {
		string str;
		for (int i = 0; i < s_len; ++i) {
			str += s[i];
			
			if (bit & (1 << i)) {
				answer += atoll(str.c_str());
				str = "";
			}
		}
		answer += atoll(str.c_str());
	}
	cout << answer << endl;
}