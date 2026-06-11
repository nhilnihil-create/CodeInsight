#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;

int main(){
	ll N, sum = 0; cin >> N;
	ll A[N];
	for(int i=0; i<N; i++){
		cin >> A[i];
		sum += A[i];
	}
	if(sum % (N*(N+1)/2) == 0){
		ll cnt = sum/(N*(N+1)/2), chk = 0;
		for(int i=0; i<N; i++){
			ll gap = A[(i+1)%N] - A[i];
			if((cnt-gap)%N == 0 && 0 <= (cnt-gap)/N && (cnt-gap)/N <= cnt){
				chk += (cnt-gap)/N;
			}else{
				cout << "NO" << "\n";
				return 0;
			}
		}
		if(chk == cnt) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}else{
		cout << "NO" << "\n";
	}
	return 0;
}