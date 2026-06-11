#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N, K, ans = 0;
	cin >> N >> K;

	vector<int> V(N);
	for (int i = 0; i < N; i++) cin >> V.at(i);

	sort(V.begin(),V.end());
	for (int i = 0; i < K; i++) ans += V.at(N - 1 - i);

	cout << ans << endl;
}