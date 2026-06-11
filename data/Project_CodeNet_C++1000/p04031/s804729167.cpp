#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define INF 100000000

int main() {
	int n, same, total, result = INF, ans = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a.at(i);
	}
	sort(a.begin(), a.end());
	same = a.at(0);

	while (same < a.at(n-1)+1) {
		total = 0;
		for (int i = 0; i < n; i++) {
			total += pow(same - a.at(i), 2);
		}
		if (result > total) {
			result = total;
		} else {
			ans = result;
			break;
		}
		same++;
	}

	cout << ans << endl;
}