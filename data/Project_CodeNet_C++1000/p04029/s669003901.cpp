#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
	int N; cin >> N;
	int l = 0;
	int c = 0;

	for (int i = 0 + 1; i <= N; i++) c += i;
	cout << c << endl;

	return 0;
}
