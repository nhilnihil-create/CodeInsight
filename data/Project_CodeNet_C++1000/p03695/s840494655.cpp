#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;

int main() {
	int n, color = 0, cool = 0, num;
	cin >> n;
	vector <int> seen(8);
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num < 3200) {
			seen[num / 400]++;
		}
		else {
			cool++;
		}
	}
	for (int k = 0; k < seen.size(); k++) {
		if (seen[k] !=  0) {
			color++;
		}
	}
	cout << max(color, 1) << " " << color + cool << endl;
	return 0;
}