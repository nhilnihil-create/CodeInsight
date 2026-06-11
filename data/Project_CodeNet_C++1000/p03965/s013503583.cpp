#include<iostream>
#include<algorithm>
#include <cassert>
#include<string>
#include<vector>
#include <utility>
#include <math.h>
#include<cmath>
#include<map>
#include <limits>
# include <iomanip>
#include<queue>
#define INF 1000000009;
#define inl long long
using namespace std;
int gcd(int a, int b) {
	while (a % b != 0) {
		int c = 0;
		c = a % b;
		a = b;
		b = c;
	}
	return  b;
}
int kaizyo(int a) {
	long long ans = 1;
	for (int i = a; i > 0; i--) {
		ans *= i;
		ans = ans % 1000000007;
		//cout << ans << endl;
	}
	ans = ans % 1000000007;
	return ans;
}
int main() {
	string manji;
	cin >> manji;
	int sco = 0;
	int gu = 0, pa = 0;
	if (manji[0] == 'p') {
		sco--;
	}
	gu++;
	for (int i = 1; i < manji.size(); i++) {
		if (manji[i] == 'g') {
			if (gu > pa) {
				sco++;
				pa++;
			}
			else {
				gu++;
			}
		}
		if (manji[i] == 'p') {
			if (gu > pa) {
				pa++;
			}
			else { gu++;
			sco--;
			}
		}
	}
	cout << sco << endl;
	return 0;
}




