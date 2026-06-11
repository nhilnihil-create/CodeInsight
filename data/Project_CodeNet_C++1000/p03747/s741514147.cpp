#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000002


int main(){

	long long N,L,T;
	cin>>N>>L>>T;
	L*=2;
	T*=2;
	vector<long long> ans(N);
	
	vector<long long> X(N),W(N);
	for(int i=0;i<N;i++){
		cin>>X[i]>>W[i];
		X[i]*=2;
		ans[i] = (X[i]+(W[i]==1?T:-T))%L;
		if(ans[i]<0)ans[i]+=L;
	}
	
	sort(ans.begin(),ans.end());
	
	long long cnt = 0LL;
	for(int i=0;i<N;i++){
		if(W[0]==W[i])continue;
		long long x;
		if(W[0]==1){
			x = X[i]-X[0];
		}
		else{
			x = X[0]-X[i];
		}
		if(x<0)x+=L;
		x/=2;
		if(x>=T)continue;
		cnt++;
		cnt += (T-x-1)/(L/2);
	}
	cnt = (N-cnt%N)%N;
	int f = -1;
	long long temp = (X[0]+(W[0]==1?T:-T))%L;
	if(temp<0)temp+=L;
	for(int i=0;i<N;i++){
		if(ans[i]==temp){
			if(W[0]==2)f=i;
			else if(f==-1)f=i;
		}
	}
	if(W[0]==1){
		f += cnt;
		f%=N;
	}
	else{
		f -= cnt;
		if(f<N)f += N;
	}

	
	for(int i=0;i<N;i++){
		cout<<ans[(f+i)%N]/2<<endl;
	}
	
	return 0;
}