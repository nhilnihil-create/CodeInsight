#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
#include<sstream>
using namespace std;


int main() {

	long long N;
	long long M;
	cin >> N >> M;

	vector<long long> p;

	long long a, b;

	for (long long i = 0; i < M; i++) {
		cin >> a >> b;
		if (a == 1) {
			p.push_back(b);
		}
		else if (b == N) {
			p.push_back(a);
		}
	}

	sort(p.begin(), p.end());

	bool jdg = false;
	for (long long i = 0; i < p.size() - 1; i++) {
		if (p[i + 1] == p[i]) {
			jdg = true;
			break;
		}
	}

	if (jdg == true) {
		cout << "POSSIBLE" << endl;
	}
	else {
		cout << "IMPOSSIBLE" << endl;
	}

	return 0;
}