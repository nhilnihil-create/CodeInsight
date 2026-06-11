#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define INF 500000001000000000
#define MOD 1000000007
typedef long long  ll;

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N,M;
	cin >> N >> M;

	vector<string> A(N),B(M);
	rep(i,N){
		cin >> A[i];
	}
	rep(i,M){
		cin >> B[i];
	}

	bool flg = false;
	rep(i,N-M+1){
		rep(j,N-M+1){
			if(A[i].substr(j,M) == B[0].substr(0,M)){
				// cout << i << " " << j << endl; 
				rep(k,M){
					if(A[i+k].substr(j,M) != B[k].substr(0,M)){
						break;
					}
					if(k == M-1){
						flg = true;
					}
				}
			}
		}
	}

	if(flg){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;

	}

	return 0;
}