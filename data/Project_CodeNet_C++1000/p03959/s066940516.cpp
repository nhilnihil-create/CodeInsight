#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;

int main(){
	int N;
	cin >> N;
	vector<ll> T(N);
	vector<ll> A(N);

	for(int i = 0;i < N;i++)cin >> T[i];
	for(int i = 0;i < N;i++)cin >> A[i];

	if(A[0] != T[N-1]){
		cout << 0 << endl;
		return 0;
	}

	int index_T = 0;
	int index_A = 0;
	for(int i = 0;i < N;i++){
		if(T[i] == T[N-1]){
			index_T = i;
			break;
		}
	}

	for(int i = N - 1;i >= 0;i--){
		if(A[i] == A[0]){
			index_A = i;
			break;
		}
	}

	if(index_T > index_A){
		cout << 0 << endl;
		return 0;
	}

	ll ans = 1;
	for(int i = 1;i < index_T;i++){
		if(T[i] == T[i-1]){
			ans *= T[i];
			ans %= MOD;
		}
	}

	for(int i = N-2;i > index_A;i--){
		if(A[i] == A[i+1]){
			ans *= A[i];
			ans %= MOD;
		}
	}

	for(int i = 0;i < (index_A - index_T - 1);i++){
		ans *= A[0];
		ans %= MOD;
	}

	cout << ans << endl;
}
