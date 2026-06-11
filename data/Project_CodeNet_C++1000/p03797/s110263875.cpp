#include <iostream>
using namespace std;

int main(){
	long long N,M;
	cin>>N>>M;
	long long ans=0;
	if(M >= 2*N){
		long long P = M-2*N;
		long long CanMake =  P/4;
		ans = N + CanMake;
	}else if(M < 2*N){
		ans =  M / 2;
	}
	cout<<ans<<endl;
	
}