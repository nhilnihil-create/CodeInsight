#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using ldbl = long double;
using P = pair<llong, llong>;

#define BE(x) x.begin(), x.end()

const llong inf = llong(1e18)+7;
const llong mod = 1e9+7;

int main(){
	llong N;
	vector<llong> A,B;

	cin >> N;
	A.resize(N);
	B.resize(N);
	for(int i = 0; i < N; i++)
		cin >> A[i];
	for(int i = 0; i < N; i++)
		cin >> B[i];

	if(N == 1){
		if(A[0] == B[0])
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}else{
		llong ans = 1;
		vector<llong> Mt(N,-1);
		for(int i = 0; i < N; i++){
			if(i == 0 || A[i] != A[i-1])
				Mt[i] = A[i];
		}
		for(int i = N-1; i >= 0; i--){
			if(i == N-1){
				if(Mt[i] == -1)
					Mt[i] = B[i];
				else if(Mt[i] != B[i]){
					ans = 0;
					break;
				}
			}else{
				if(Mt[i] == -1){
					if(B[i] != B[i+1])
						Mt[i] = B[i];
				}else if(Mt[i] > B[i]){
					ans = 0;
				}
			}
		}

		for(auto x : Mt)
			cerr << x << " ";
		cerr << endl;

		for(int i = 0; i < N; i++){
			if(Mt[i] != -1)
				continue;

			ans *= min(A[i], B[i]);
			ans %= mod;
		}

		cout << ans << endl;
	}

	return 0;
}