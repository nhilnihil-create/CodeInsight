#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

int main() {

	int N;
	int A[100000];
	cin >> N;
	for (int i = 0; i < N; i++)cin >> A[i];
	sort(A, A + N);
	if (A[N - 1] - A[0] >= 2) {
		cout << "No" << endl;
	}
	else if (A[N - 1] - A[0] == 1){
		int cnt = 1;
		while (cnt < N && A[0] == A[cnt])cnt++;
		if (A[0] != A[A[0]] && (A[0] - cnt + 1) * 2 <= N - cnt)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	else {
		if (A[0] == N - 1 && A[N - 1] == N - 1) {
			cout << "Yes" << endl;
		}
		else if (A[0] * 2 <= N) {
			cout << "Yes" << endl;
		}
		else cout << "No" << endl;
	}
	return 0;
}