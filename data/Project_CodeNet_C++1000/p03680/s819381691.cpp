#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;


int main(int argc, char *argv[]) {

	int N; cin >> N;

	vector<int> A(N,0);
	for (int i = 0; i < N; i++) {
		cin >> A[i];	
	}

	int next = A[0];
	int ans = 1;
	while(next != 2) {
		next = A[next-1];
		ans++;
		if (ans > pow(10,6)) {
			ans = -1;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
