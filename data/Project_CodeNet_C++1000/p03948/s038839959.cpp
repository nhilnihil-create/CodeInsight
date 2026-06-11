#include<bits/stdc++.h>
using namespace std;

int main(){
	int N, T;
	cin >> N >> T;
// mmax[i] は、A[i+1] ~ A[N-1] の最大
	int A[N], mmax[N-1];
	for(int i=0; i<N; i++) cin >> A[i];
	int m = A[N-1];
	mmax[N-2] = m;
	for(int i=N-3; i>=0; i--){
		if(m < A[i]) m = A[i];
		mmax[i] = m;
	}
	int MAX = mmax[0] - A[0], cnt = 0;
	for(int i=1; i<N-1; i++){
		if(MAX < mmax[i] - A[i]) MAX = mmax[i] - A[i];
	}
	for(int i=0; i<N-1; i++){
		if(mmax[i] - A[i] == MAX) cnt++;
	}
	cout << cnt << endl;
	return 0;
}