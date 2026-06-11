#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647

int main() {
	int N;
	cin >> N;
	vector<int> vec(N);
	int sum = 0;
	bool flags = false;
	for (int i = 0; i < N; ++i) {
		cin >> vec[i];
		sum += vec[i];
		if (vec[i] % 10 != 0) {
			flags = true;
		}
	}


	if (flags == false) {
		cout << 0 << endl;
	}
	else {
		if (sum % 10 == 0) {
			sort(vec.begin(), vec.end());
			for (size_t t = 0; t < vec.size(); ++t) {
				if (vec[t] % 10 != 0) {
					cout << sum - vec[t] << endl;
					break;
				}
			}
		}
		else {
			cout << sum << endl;
		}
	}

	return 0;
}