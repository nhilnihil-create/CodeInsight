#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int K, T;
	cin >> K >> T;
	int Odd = 0, Even = 0;
	vector<int>A(T);
	for (int i = 0; i < T; i++) cin >> A[i];
	sort(A.begin(), A.end(), greater<int>());
	for (int a : A) (Odd < Even ? Odd : Even) += a;

	cout << max(abs(Odd - Even) - 1, 0) << endl;
}