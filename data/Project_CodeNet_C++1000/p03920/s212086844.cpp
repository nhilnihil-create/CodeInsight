#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int N, over = 0, sum = 0;
	int ans = 0, move = 0;
	cin >> N;
	for (int i = 1; i <= (N + 2) / 2; i++) {
		sum = (1 + i)*i / 2;
		if (sum > N) {
			over = i;
			break;
		}
		else if (sum == N) {
			ans = i;
			break;
		}
	}
	if (ans != 0) {
		for (int i = 1; i <= ans; i++) {
			cout << i << endl;
		}
	}
	else {
		int remove = sum - N;
		for (int i = 1; i <= over; i++) {
			if (i != remove)cout << i << endl;
		}
	}
	return 0;
}