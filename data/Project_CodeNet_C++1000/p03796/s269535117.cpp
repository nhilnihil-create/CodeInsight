#include <iostream>
using namespace std;

int main(){
	long long N;
	cin>>N;
	long long MOD = 1000000000+7;
	long long ans=1;

	for(int i=1;i<=N;i++){
		ans = ((ans % MOD)*(i % MOD))%MOD;
	}
	cout<<ans<<endl;
}