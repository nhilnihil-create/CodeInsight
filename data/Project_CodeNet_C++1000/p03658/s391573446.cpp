// ABC067B - 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> l(N);
	for (int i = 0; i < N; i++) {
		cin >> l[i];
	}
	sort(l.begin(), l.end(), greater<int>());

	int sum = 0;
	for (int i = 0; i < K; i++) {
		sum += l[i];
	}

	cout << sum << endl;

	return 0;
}
