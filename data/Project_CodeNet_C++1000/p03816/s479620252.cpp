
// D - Card Eater

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	map<int, int> counter;

	for (int i=0; i<N; i++) {
		int A;
		cin >> A;
		counter[A]++;
	}

	int num_even = 0;
	for (auto itr=counter.begin(); itr!=counter.end(); itr++) {
		if (itr->second % 2 == 0) {
			num_even++;
		}
	}

	int ans;

	if (num_even % 2 == 0) ans = counter.size();
	else ans = counter.size() - 1;

	cout << ans << endl;

	return 0;
}