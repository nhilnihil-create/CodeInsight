#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;

	int n = (int)s.size();
	long long sum = 0;

	for (int bit = 0; bit < (1 << (n - 1)); bit++) {
		string s2 = s;
		long long num = 0;
		int temp = 0;
		for (int i = 0; i < n - 1; i++) {
			if (bit & (1 << i)) {
				temp++;
				s2.insert(i + temp, "+");
			}
		}
		for (int i = 0; i < s2.size() + 1; i++) {
			if (s2[i] == '+' || s2[i] == '\0') {
				sum += num;
				num = 0;
			}
			else {
				num = num * 10 + (s2[i] - '0');
			}
		}
	}

	cout << sum << endl;

	return 0;
}