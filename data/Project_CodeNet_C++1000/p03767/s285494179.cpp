
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
	
	int N; cin >> N;
	vector<int> A(N * 3);
	for (int i = 0; i < A.size(); ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end(), greater<int>());

	ll sum = 0;
	for (int i = 0; i < N; ++i) {
		sum += A[i * 2 + 1];
	}
	cout << sum << endl;
}