#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int A,B,C,D,result = 0;
	vector<int> data;

	cin >> A >> B >> C >> D;

	if (B < C || D < A) {
		cout << 0;
		return 0;
	}

	data.push_back(A);
	data.push_back(B);
	data.push_back(C);
	data.push_back(D);

	sort(data.begin(), data.end());


	result = data[2] - data[1];
	if (result < 0) result = 0;

	cout << result;

	return 0;
}