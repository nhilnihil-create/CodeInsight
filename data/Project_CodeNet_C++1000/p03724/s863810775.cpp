#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000


int main(){
	
	int N,M;
	cin>>N>>M;
	
	vector<int> S(N+5,0);
	
	for(int i=0;i<M;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		if(a>b)swap(a,b);
		S[a+1]++;
		S[b+1]--;
	}
	
	for(int i=1;i<N;i++){
		S[i] += S[i-1];
		if(S[i]%2==1){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	
	cout<<"YES"<<endl;
	
	return 0;
}