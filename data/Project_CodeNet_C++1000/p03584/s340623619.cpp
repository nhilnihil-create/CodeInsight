#include <iostream>
using namespace std;

int main() {
	int N, K, A[100010], B[100010];
	cin >> N >> K;
	long ans=0;
	for(int i=0; i<N; ++i){
	    cin >> A[i] >> B[i];
	    if((A[i]|K) == K) ans += B[i];
	}
	for(int x=0; x<31; ++x){
	    if(K&(1<<x)){
	        int L=K;
	        long now=0;
	        L &= ~(1<<x);
	        for(int y=0; y<x; ++y) L |= (1<<y);
	        for(int i=0; i<N; ++i) if((A[i]|L) == L) now += B[i];
	        ans=max(ans, now);
	    }
	}
	cout << ans << endl;
	return 0;
}
