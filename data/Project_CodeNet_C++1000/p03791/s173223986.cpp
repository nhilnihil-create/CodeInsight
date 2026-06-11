#include <iostream>
using namespace std;

const long long P = 1000000007;
int x[123456];
int main() {
	// your code goes here
	int n;
	cin >> n;
	long long ret = 1;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0, j = 0; i < n; i++) {
		while(j < n - 1 && x[j] > 2 * (j - i)) j++;
		ret = (ret * (j + 1 - i)) % P;
	}
	cout << ret << endl;
	return 0;
}