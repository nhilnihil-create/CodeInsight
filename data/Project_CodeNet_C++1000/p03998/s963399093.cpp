#include "bits/stdc++.h"
using namespace std;

int main() {
	string A, B, C;
	cin >> A >> B >> C;
	queue<int> a;
	queue<int> b;
	queue<int> c;
	for (int i = 0; i < A.size(); ++i) {
		a.push(A[i] - 'a');
	}
	for (int i = 0; i < B.size(); ++i) {
		b.push(B[i] - 'a');
	}
	for (int i = 0; i < C.size(); ++i) {
		c.push(C[i] - 'a');
	}
	int now = 0;
	while (true) {
		if (0 == now) {
			if (0 == a.size()) {
				break;
			}
			now = a.front();
			a.pop();
		}
		else if (1 ==now) {
			if (0 == b.size()) {
				break;
			}
			now = b.front();
			b.pop();
		}
		else {
			if (0 == c.size()) {
				break;
			}
			now = c.front();
			c.pop();
		}
	}
	cout << (char)('A'+now)<< endl;
	return 0;
}