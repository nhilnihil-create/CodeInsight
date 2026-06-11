#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
using namespace std;
int main() {
	int N, K;
	int ans = 0;
	cin >> N >> K;
	vector<int> x(N);
	for (int i = 0; i < N; i++) {
		cin >> x.at(i);
		ans += 2*min(abs(K - x.at(i)), abs(x.at(i)));
	}
	cout << ans << endl;
	return 0;
}
