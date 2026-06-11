#include <bits/stdc++.h>

using namespace std;

int main() {

	long n;
	cin >> n;

	map<long, long> a;
	long tmp;

	for (long i = 0; i < n; i++) {
		cin >> tmp;
		a[tmp]++;
	}

	long counter = 0;
	auto itr = a.begin();
	do {
		while (itr->second > 2) {
			itr->second -= 2;
			counter++;
			counter++;
		}
		itr = next(itr, 1);
	} while (itr != a.end());

	itr = a.begin();
	long count2 = 0;

	vector<long> c2;
	do {
		if (itr->second == 2) {
			c2.push_back(itr->first);
		}
		itr = next(itr, 1);
	} while (itr != a.end());

	if (c2.size() % 2 == 0 ) {
		counter += c2.size();
	}
	else  {
		counter += c2.size()+1;
	}
	
	cout << n-counter << endl;

	return 0;
}