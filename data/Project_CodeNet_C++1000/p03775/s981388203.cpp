#include <iostream>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
	long long int n;
	cin >> n;

	int a[100000];
	int yakuSize = 0;

	for (long long int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			a[yakuSize++] = n / i;
		}
	}

	int ans = a[yakuSize - 1];
	int keta = 1;
	while (ans / 10 != 0) {
		ans /= 10;
		++keta;
	}
	cout << keta << endl;
}