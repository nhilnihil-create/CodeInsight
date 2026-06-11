#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) (V).begin(),(V).end()

void ans(vector<bool>&V) {
	for (bool i : V) {
		if (i)cout << 'S';
		else cout << 'W';
	}
	cout << endl;
}

int main(){
	int N;
	cin >> N;
	string S;
	cin >> S;
	vector<bool> A(N);

	// 1が羊 Nが羊
	A[0] = 1;
	if (S[0] == 'o')A[1] = 1;
	else A[1] = 0;
	for (int i = 1;i < N - 1;i++) {
		if (S[i] == 'o') {
			if (A[i])A[i + 1] = A[i - 1];
			else A[i + 1] = !A[i - 1];
		}
		else {
			if (A[i])A[i + 1] = !A[i - 1];
			else A[i + 1] = A[i - 1];
		}
	}
	if (A[N - 1]) {
		if (S[N - 1] == 'o' && A[N - 2] == A[0]) {
			ans(A);
			return 0;
		}
		if (S[N - 1] == 'x' && A[N - 2] != A[0]) {
			ans(A);
			return 0;
		}
	}

	// 1が羊 Nが狼
	A[0] = 1;
	if (S[0] == 'o')A[1] = 0;
	else A[1] = 1;
	for (int i = 1;i < N - 1;i++) {
		if (S[i] == 'o') {
			if (A[i])A[i + 1] = A[i - 1];
			else A[i + 1] = !A[i - 1];
		}
		else {
			if (A[i])A[i + 1] = !A[i - 1];
			else A[i + 1] = A[i - 1];
		}
	}
	if (!A[N - 1]) {
		if (S[N - 1] == 'o' && A[N - 2] != A[0]) {
			ans(A);
			return 0;
		}
		if (S[N - 1] == 'x' && A[N - 2] == A[0]) {
			ans(A);
			return 0;
		}
	}

	// 1が狼 Nが羊
	A[0] = 0;
	if (S[0] == 'o')A[1] = 0;
	else A[1] = 1;
	for (int i = 1;i < N - 1;i++) {
		if (S[i] == 'o') {
			if (A[i])A[i + 1] = A[i - 1];
			else A[i + 1] = !A[i - 1];
		}
		else {
			if (A[i])A[i + 1] = !A[i - 1];
			else A[i + 1] = A[i - 1];
		}
	}
	if (A[N - 1]) {
		if (S[N - 1] == 'o' && A[N - 2] == A[0]) {
			ans(A);
			return 0;
		}
		if (S[N - 1] == 'x' && A[N - 2] != A[0]) {
			ans(A);
			return 0;
		}
	}

	// 1が狼 Nが狼
	A[0] = 0;
	if (S[0] == 'o')A[1] = 1;
	else A[1] = 0;
	for (int i = 1;i < N - 1;i++) {
		if (S[i] == 'o') {
			if (A[i])A[i + 1] = A[i - 1];
			else A[i + 1] = !A[i - 1];
		}
		else {
			if (A[i])A[i + 1] = !A[i - 1];
			else A[i + 1] = A[i - 1];
		}
	}
	if (!A[N - 1]) {
		if (S[N - 1] == 'o' && A[N - 2] != A[0]) {
			ans(A);
			return 0;
		}
		if (S[N - 1] == 'x' && A[N - 2] == A[0]) {
			ans(A);
			return 0;
		}
	}

	cout << -1 << endl;
}