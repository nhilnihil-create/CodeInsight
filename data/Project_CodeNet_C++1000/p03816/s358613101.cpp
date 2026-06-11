#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	map<int, bool> m;
	for (int i = 0; i < N; i++) m[A[i]] = true;
	int ans = m.size();
	if (ans % 2 == 0) ans--;
	cout << ans << endl;
}
