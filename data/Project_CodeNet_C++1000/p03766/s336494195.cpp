#include<bits/stdc++.h>
using namespace std;

typedef int int_t;
#define int long long

const int maxn=1e6+5;
const int mod =1e9+7;

int F[maxn],S[maxn],N;

int_t main(){
	cin>>N;F[1]=N;S[1]=N;
	int pp=(N-1)*(N-1)%mod;
	for(int i=2;i<=N;i++){
		F[i]=(S[max(i-3,0ll)]+(N-max(i-1,2ll)+1)+F[i-1]+pp)%mod;
		S[i]=(S[i-1]+F[i])%mod;
	}
	cout<<F[N]<<'\n';
	return 0;
}
