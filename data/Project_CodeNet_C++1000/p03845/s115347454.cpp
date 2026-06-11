#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	int T[N+1];
	int tt = 0;
	rep(i,N) {
		cin >> T[i+1];
		tt += T[i+1];
	}
	int M;
	cin >> M;
	rep(i,M) {
		int p, x;
		cin >> p >> x;
		cout << tt+x-T[p] << endl;
	}

	return 0;
}
