#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int N, A, a = 0;
	cin >> N;
	unordered_map<int, int> b;
	for (int i = 0; i < N; i++) {
		cin >> A;
		b[A]++;
	}
	for (const pair<int, int>& i : b) {
		if (i.second % 2 == 0) a++;
	}
	if (a % 2) cout << b.size() - 1;
	else cout << b.size();
}