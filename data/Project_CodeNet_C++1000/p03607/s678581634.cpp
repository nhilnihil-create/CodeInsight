#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	int A[N];
	rep(i,N) cin >> A[i];
	sort(A, A+N);
	int ans = 0;
	int c = 1;
	int now = A[0];
	for (int i = 1; i < N; i++) {
		if (A[i] == now) c++;
		else {
			ans += c%2;
			now = A[i];
			c = 1;
		}	
	}
	ans += c%2;
	cout << ans << endl;
	
	return 0;
}
