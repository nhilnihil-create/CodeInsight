#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<char, int> P;

int main() {
	int N;
	cin >> N;
	int sum = 0;
	int i;
	for (i = 1; i <= N; i++) {
		sum += i;
		if (sum >= N) break;
	}
	for (int j = 1; j <= i; j++) {
		if (j != sum - N) cout << j << endl;
	}
}