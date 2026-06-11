#include <iostream>
using namespace std;

int n = 50;
long long a[50];

int main() {
	ios_base::sync_with_stdio(0);
	long long k;
	cin >> k;
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}
	
	for (int i = 0; i < n; i++) {
		a[i] += k / n;
	}
	
	for (long long i = 0; i < k % n; i++) {
		a[i] += n;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			a[j]--;
		}
	}
	
	cout << n << "\n";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	
    return 0;
}
