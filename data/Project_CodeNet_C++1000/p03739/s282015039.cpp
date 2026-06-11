#include "bits/stdc++.h"
using namespace std;


int main() {

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0;i < n;i++) {
		cin >> a.at(i);
	}

	int64_t sum = a.at(0);
	int64_t count_eve = 0;
	int64_t count_odd = 0;

	if (a.at(0) <= 0) {
		count_eve += -sum + 1;
		sum = 1;
	}
	for (int i = 0;i < n - 1;i++) {
		if (i % 2 == 0) {
			if (sum + a.at(i + 1) < 0) {
				sum += a.at(i + 1);
			}
			else {
				count_eve += sum + a.at(i + 1) + 1;
				sum = -1;
			}
		}
		else {
			if (sum + a.at(i + 1) > 0) {
				sum += a.at(i + 1);
			}
			else {
				count_eve += -sum - a.at(i + 1) + 1;
				sum = 1;
			}
		}
	}
	
	sum = a.at(0);
	if (a.at(0) >= 0) {
		count_odd += sum + 1;
		sum = -1;
	}
	for (int i = 0;i < n - 1;i++) {
		if (i % 2 == 0) {
			if (sum + a.at(i + 1) > 0) {
				sum += a.at(i + 1);
			}
			else {
				count_odd += -sum - a.at(i + 1) + 1;
				sum = 1;
			}
		}
		else {
			if (sum + a.at(i + 1) < 0) {
				sum += a.at(i + 1);
			}
			else {
				count_odd += sum + a.at(i + 1) + 1;
				sum = -1;
			}
		}
	}
	cout << min(count_eve,count_odd);

}