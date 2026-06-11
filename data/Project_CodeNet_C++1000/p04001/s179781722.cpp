#include"bits/stdc++.h"
using namespace std;

int main() {
	string s; cin >> s;
	int n = s.size() - 1;
	vector<int> a(s.size());
	for (int i = 0; i < s.size(); i++)
	{
		a.at(i) = s.at(i) - '0';
	}
	int64_t sum = 0;
	for (int bit = 0; bit < (1 << n); bit++) {
		int64_t tmp = a.at(0);
		for (int i = 0; i < n; i++)
		{
			if ((1 << i) & bit) {
				sum += tmp;
				tmp = a.at(i + 1);
			}
			else {
				tmp *= 10;
				tmp += a.at(i+1);
			}
		}
		sum += tmp;
	}
	cout << sum << endl;
}