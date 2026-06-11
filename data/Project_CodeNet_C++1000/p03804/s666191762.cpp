#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	char A[N][N];
	char B[M][M];
	rep(i,N)rep(j,N) cin >> A[i][j];
	rep(i,M)rep(j,M) cin >> B[i][j];
	rep(k,N-M+1)rep(l,N-M+1) {
		bool flag = true;
		rep(i,M){
			rep(j,M) {
				if (A[k+i][l+j] != B[i][j]) {
					flag = false;
					break;
				}
			}
			if (!flag) break;
		}

		if (flag) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
