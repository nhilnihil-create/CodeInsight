#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <numeric>
#include <string>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;

	int kaigai = 0;
	int gakusei = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] == 'b') kaigai++;

		if (s[i] == 'a' && gakusei < a + b) {
			cout << "Yes" << endl;
			gakusei++;
		}
		else if (s[i] == 'b' && gakusei < a + b && kaigai <= b) {
			cout << "Yes" << endl;
			gakusei++;
		}
		else {
			cout << "No" << endl;
		}

		//if (s[i] == 'c')cout << "No" << endl;
	}
	return 0;
}
