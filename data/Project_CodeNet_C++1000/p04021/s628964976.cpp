#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<functional>
#include <random>
#include<iostream>
#include<iomanip>
using namespace std;

int N;
pair<int, int> A[100000];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i].first;
		A[i].second = i;
	}

	sort(A, A + N);


	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			if (A[i].second % 2 == 1) {
				ans += 1;
			}
		}
	}
	cout << ans;
}