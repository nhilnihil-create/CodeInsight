// D - No Need
#include <bits/stdc++.h>
using namespace std;

int main(){
	int N,K; cin>>N>>K;

	vector<int> A(N);
	for(int i=0; i<N; ++i) cin>>A[i];
	sort(A.begin(), A.end());

	int ans = N;
	int sum = 0;
	for(int i=N-1; i>=0; --i){
		if(sum+A[i]<K) sum += A[i];
		else ans = i;
	}
	cout<< ans <<endl;
}