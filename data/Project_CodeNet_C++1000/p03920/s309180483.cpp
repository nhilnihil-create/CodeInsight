#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	int sum = 0;
	bool find = false;
	vector<int> ps;
	for (int i = 1; !find && i < N+1; ++i) {
		if (sum+i >= N) {
			sum += i;
			ps.push_back(i);
			find = true;
		}
		else {
			sum += i;
			ps.push_back(i);
		}
	}

	int ns = sum - N;
	for (size_t i = 0; i < ps.size(); ++i) {
		if (ns != ps[i]) {
			cout << ps[i] << endl;
		}
	}

	return 0;
}
