#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, P[100000], count = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}
	for (int i = 0; i < N; i++) {
		if (P[i] == i + 1) {
			count++;
			i++;
		}
	}
	cout << count;
}