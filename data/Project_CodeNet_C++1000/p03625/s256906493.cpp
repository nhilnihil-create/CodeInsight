#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	vector<int64_t> v(N);
	for (int i = 0; i < N; i++) cin >> v.at(i);
	sort(v.begin(), v.end());

	bool b = false;
	int cnt = 1;
	vector<int64_t> va;

	for (int i = N - 1; i > 0; i--) {
		if (v.at(i) == v.at(i - 1)) {
			cnt++;
		}

		if ((i == 1) || (v.at(i) != v.at(i - 1))) {
			if (cnt >= 4) {
				va.push_back(v.at(i));
				b = true;
				break;
			}
			else if (cnt >= 2) {
				va.push_back(v.at(i));
				cnt = 1;

				if (va.size() > 1) {
					b = true;
					break;
				}
			}
		}

		//cout << cnt << endl;
	}

	//for (int i = 0; i < va.size(); i++) cout << va.at(i) << endl;

	if (!b) {
		cout << 0 << endl;
	}
	else {
		if (va.size() == 1) {
			cout << va.at(0) * va.at(0) << endl;
		}
		else {
			cout << va.at(0) * va.at(1) << endl;
		}
	}
}