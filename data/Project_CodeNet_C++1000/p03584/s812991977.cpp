#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000

long long get(long long K,vector<long long> &A,vector<long long> &B){
	long long ret = 0;
	for(int i=0;i<A.size();i++){
		if((A[i]|K)==K){
			ret += B[i];
		}
	}
	return ret;
}

int main(){
	
	int N,K;
	cin>>N>>K;
	
	vector<long long> A(N),B(N);
	for(int i=0;i<N;i++)cin>>A[i]>>B[i];
	
	long long ans = get(K,A,B);
	
	for(int i=0;i<30;i++){
		if((1<<i)&K){
			long long t = K|((1<<i)-1);
			t ^= (1<<i);
			ans = max(ans,get(t,A,B));
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}