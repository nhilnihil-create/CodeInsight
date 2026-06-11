#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000


int main(){
	int N,K;
	cin>>N>>K;
	
	vector<long long> a(N);
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	
	vector<long long> S(N+1,0),S_p(N+1,0);
	
	for(int i=0;i<N;i++){
		S[i+1] = S[i] + a[i];
		S_p[i+1] = S_p[i];
		if(a[i]>0)S_p[i+1]+=a[i];
	}
	
	long long ans = 0;
	
	for(int i=1;i<=N;i++){
		int r = i+K-1;
		if(r>N)break;
		
		long long a = max((long long)0,S[r]-S[i-1]);
		a += S_p[i-1];
		a += S_p[N]-S_p[r];
		ans = max(a,ans);
	}
	
	cout<<ans<<endl;
	
	
	
	return 0;
}
