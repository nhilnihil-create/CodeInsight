#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	int total = 1;
	while (total <= N) {
		total *= 2;
		if (total > N) {
			total /= 2;
			break;
		}
	}
	cout << total << endl;
}
