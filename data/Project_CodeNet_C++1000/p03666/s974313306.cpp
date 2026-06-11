#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000



int main(){
	
	long long N,A,B,C,D;
	cin>>N>>A>>B>>C>>D;
	
	A-=B;
	
	for(long long i=0;i<=N-1;i++){
		long long L = C*i - D*(N-1-i);
		long long R = D*i - C*(N-1-i);
		if(L<=A&&A<=R){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	
	cout<<"NO"<<endl;
	
	return 0;
}