#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
#include<set>
#include<map>

using namespace std;
long long MOD = 1000000007LL;
const double PI = 3.14159265358979323846;
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define endl "\n"

int main() {
	int N;
	long long x;
	cin >> N >> x;
	vector<long long> A(N);
	vector<long long> B(N - 1, 0);
	for (int i = 0; i < N; ++i)cin >> A[i];

	long long count = 0;
	for (int i = 0; i < B.size(); ++i) {
		B[i] = A[i] + A[i + 1];
		if (x < B[i]) {
			long long buf = B[i] - x;
			count += buf;
			A[i + 1] = max(A[i + 1] - buf, 0ll);
		}
	}

	cout << count << endl;
	return 0;
}