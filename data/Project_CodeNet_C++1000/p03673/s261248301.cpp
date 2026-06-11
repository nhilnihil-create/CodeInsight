#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N;
    cin >> N;

	vector<long long> even;
	vector<long long> odd;

	long long a;
	for (long long i = 1; i <= N; ++i) {
		cin >> a;
		if (i % 2 == 1) {
			odd.push_back(a);
		} else {
			even.push_back(a);
		}
	}

	vector<long long> b;
	if (N % 2 == 1) {
		for (long long i = odd.size() - 1; i >= 0; --i) {
			b.push_back(odd[i]);
		}
		for (long long i = 0; i < even.size(); i++) {
			b.push_back(even[i]);
		}
	} else {
		for (long long i = even.size() - 1; i >= 0; --i) {
			b.push_back(even[i]);
		}
		for (long long i = 0; i < odd.size(); ++i) {
			b.push_back(odd[i]);
		}
	}

	for (long long i = 0; i < b.size(); ++i) {
		cout << b[i] << " ";
	}
	cout << endl;

	return 0;
}
