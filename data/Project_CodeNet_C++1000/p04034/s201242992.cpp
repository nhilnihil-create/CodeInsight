#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long N, M; cin >> N >> M;
	vector<long long>A(N, 1);
	vector<bool>D(N, false);
	D.at(0) = true;
	for (long long i = 0; i < M; i++) {
		long long B, C; cin >> B >> C;
		A.at(B - 1)--;
		A.at(C - 1)++;
		if (D.at(B - 1))D.at(C - 1) = true;
		if (A.at(B - 1) == 0) D.at(B - 1) = false;
	}
	long long ans = 0;
	for (long long i = 0; i < N; i++) {
		if (D.at(i)) ans++;
	}
	cout << ans << endl;
}