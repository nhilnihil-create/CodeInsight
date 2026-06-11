#include <iostream>
using namespace std;

int main() {
	int N, T[100010], A[100010]; cin >> N;
	for(int i=1; i<=N; ++i) cin >> T[i];
	for(int i=1; i<=N; ++i) cin >> A[i];
	T[0]=0, A[N+1]=1000000001;
	long ans=1, mod=1000000007;
	for(int i=1; i<=N; ++i){
	    if(T[i]==T[i-1] && A[i]==A[i+1]) ans=(ans*min(T[i], A[i]))%mod;
	    else{
	        if(T[i-1]<T[i] && T[i]>A[i]) ans=0;
	        if(A[i]<A[i+1] && A[i]>T[i]) ans=0;
	    }
	}
	cout << ans << endl;
	return 0;
}
