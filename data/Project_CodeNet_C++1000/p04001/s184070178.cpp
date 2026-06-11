#include"bits/stdc++.h"
using namespace std;

int main() {
	string num;
	cin >> num;
	long long sum = 0;
	int a = num.size();

	for (int bit = 0; bit < (1 << a - 1); bit++) {
		long long tmp = 0;
		for (int i = 0; i < a-1; i++)
		{
			tmp *= 10;
			tmp += num.at(i) - '0';
			if ((bit >> i) & 1) {
				sum += tmp;
				tmp = 0;
			}
		}
		tmp *= 10;
		tmp += num.at(a-1) - '0';
		sum += tmp;
	}
	cout << sum << endl;
}