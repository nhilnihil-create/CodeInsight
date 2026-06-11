#include <iostream>
#include <cstdio>

using namespace std;

#define N 50

int main() {
	long long int K; 
	long long int a[N];

	cin >> K;

	for (int i = 0; i < N; i++) a[i] = i;

	long long int div = K / N;
	long long int rem = K % N;

	for (int i = 0; i < N; i++) a[i] += div;

	if (rem != 0){
		for (int i = 1; i <= rem; i++) {
			for (int j = 0; j < N; j++) {
				if (j == i - 1) a[j] += N;
				else a[j]--;
			}
		}
	}

	cout << N << endl;
	for (int i = 0; i < N; i++) {
		if (i == N - 1) cout << a[i] << endl;
		else cout << a[i] << ' ';
	}

	return 0;

}