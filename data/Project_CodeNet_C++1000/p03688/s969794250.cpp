#include <bits/stdc++.h>
using namespace std;
#define all(V) V.begin(),V.end()
#define ll long long
#define MOD 1000000007

int main(){
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0;i < N;i++) {
		cin >> A[i];
	}
	sort(all(A));
	if (A[N - 1] - A[0] > 1) {
		cout << "No" << endl;
		return 0;
	}
	//not soloがいる場合
	int solo = 0;
	for (int i = 0;i < N;i++) {
		if (A[i] != A[N - 1])solo++;
	}

	if (A[N - 1] - solo <= 0) {
		cout << "No" << endl;
		return 0;
	}
	if ((A[N - 1] - solo) * 2 <= N - solo) {
		cout << "Yes" << endl;
		return 0;
	}
	//all soloの場合
	if (A[0] != A[N - 1]) {
		cout << "No" << endl;
		return 0;
	}
	if (A[0] == N - 1) {
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
	return 0;
}