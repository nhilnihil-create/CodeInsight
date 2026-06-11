#include <iostream>
#include <vector>
using namespace std;

// EK LOOP M BHI HO SKTA THA

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A.at(i);
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int tmp = A.at(i);
		if (A.at(tmp - 1) == i + 1) {
			cnt++;
		}
	}
	cout << cnt / 2 << endl;
}
