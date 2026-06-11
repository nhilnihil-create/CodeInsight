#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000


int main(){
	long long N;
	cin>>N;
	
	long long sum = 0;
	
	vector<long long> A(N);
	for(int i=0;i<N;i++){
		cin>>A[i];
		sum += A[i];
	}
	
	if(N==1){
		cout<<"YES"<<endl;
		return 0;
	}
	
	
	long long K = N*(N+1)/2;
	
	if(sum%K!=0){
		cout<<"NO"<<endl;
		return 0;
	}
	
	sum /= K;
	
	vector<long long> B(N);
	for(int i=0;i<N;i++){
		if(i==0)B[i] = A[i]-A[N-1];
		else B[i] = A[i]-A[i-1];
		B[i] -= sum;
	}
	long long cnt = 0;
	for(int i=0;i<N;i++){
		if(B[i]>0){
			cout<<"NO"<<endl;
			return 0;
		}
		B[i]*=-1;
		if(B[i]%(N)!=0){
			cout<<"NO"<<endl;
			return 0;
		}
		cnt += B[i]/(N);
	}
	
	if(cnt!=sum){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
	}
	
	
	
	
	
	
	return 0;
}
