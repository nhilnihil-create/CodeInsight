#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include<algorithm>
#include<sstream>
#include<iomanip>


using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	ll score_t, score_a;
	cin >> score_t >> score_a;

	for (int i = 0; i < n - 1; i++) {
		int t, a;
		cin >> t >> a;
		if (score_t %t != 0) {
			score_t += t - (score_t%t);
		}
		if (score_a %a != 0) {
			score_a += a - (score_a %a);
		}

		if (score_a / a < score_t / t) {
			score_a = score_t / t * a;
		}
		else {
			score_t = score_a / a * t;
		}
	}
	
	cout << score_a + score_t << endl;
}
