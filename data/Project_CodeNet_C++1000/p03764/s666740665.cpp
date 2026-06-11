#include <iostream>
using namespace std;

int main() {
	long N, M, x[100010], y[100010], mod=1000000007; cin >> N >> M;
	for(int i=0; i<N; ++i) cin >> x[i];
	for(int i=0; i<M; ++i) cin >> y[i];
	long XSUM=0, YSUM=0, mul, Int;
	for(int i=1; i<N; ++i){
	    mul=(i*(N-i))%mod, Int=(x[i]-x[i-1])%mod;
	    XSUM=(XSUM+Int*mul)%mod;
	}
	for(int i=1; i<M; ++i){
	    mul=(i*(M-i))%mod, Int=(y[i]-y[i-1])%mod;
	    YSUM=(YSUM+Int*mul)%mod;
	}
	cout << (XSUM*YSUM)%mod << endl;
	return 0;
}
