#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long

int A[310][310];

signed main(){
	int N;
	cin >> N;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	int res = 0;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			res += A[i][j];
			bool f = false;
			for(int k = 0; k < N; ++k) {
				if(i == k || j == k) continue;
				int d = A[i][k] + A[k][j];
				if(d < A[i][j]) {
					cout << -1 << endl;
					return 0;
				}
				if(d == A[i][j]) {
					f = true;
				}
			}
			if(f) {
				res -= A[i][j];
			}
		}
	}
	cout << res / 2 << endl;
	return 0;
}
