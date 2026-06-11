#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int MAX = 0, P = 0;
	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;
		if (A > MAX) {
			MAX = A;
			P = B;
		}
	}
	cout << MAX + P << endl;
}
