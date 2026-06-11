#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000


int main(){
	int N;
	cin>>N;
	vector<long long> x(N);
	vector<long long> d(N-1);
	for(int i=0;i<N;i++){
		cin>>x[i];
		if(i!=0){
			d[i-1] = x[i] - x[i-1];
		}
	}
	
	
	
	long long M,K;
	cin>>M>>K;
		
	vector<long long> v(N-1);
	for(int i=0;i<N-1;i++){
		v[i]=i;
	}
	
	for(int i=0;i<M;i++){
		int b;
		cin>>b;
		swap(v[b-2],v[b-1]);
	}
	
	
	while(K!=0){
		if(K%2==1){
			
			vector<long long> dd(N-1);
			for(int i=0;i<N-1;i++){
				dd[i] = d[v[i]];
			}
			d=dd;
		}
		vector<long long> c=v;
		for(int i=0;i<N-1;i++){
			c[i] = v[c[i]];
		}
		v=c;
		K/=2;
	}
	
	for(int i=1;i<N;i++){
		x[i] = x[i-1] + d[i-1];
	}
	
	for(int i=0;i<N;i++){
		cout<<x[i]<<endl;
	}
	
	
	
	
	
	return 0;
}
