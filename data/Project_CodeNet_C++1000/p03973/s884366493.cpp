#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000

int main(){

	int N;
	cin>>N;
	
	vector<long long> A(N);
	
	for(int i=0;i<N;i++)cin>>A[i];
	
	int now = 1;
	
	long long ans = 0;
	
	for(int i=0;i<N;i++){
		if(A[i]==now){
			now ++;
			continue;
		}
		else{
			ans += (A[i]-1)/now;
			if(now==1)now++;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}