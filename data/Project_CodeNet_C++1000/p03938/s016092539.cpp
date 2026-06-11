#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000


int main(){
	long long N;
	cin>>N;
	
	vector<long long> p(N);
	for(long long i=0;i<N;i++){
		cin>>p[i];
		p[i]--;
	}
	int k = 20005;
	vector<long long> a(N),b(N);
	for(long long i=0;i<N;i++){
		a[i]=(i+1)*k;b[i]=(N-(i))*k;
	}
	
	for(int i=0;i<N;i++){
		a[p[i]] += i+1;
	}
	
	
	for(long long i=0;i<N;i++){
		if(i!=0)cout<<' ';
		cout<<a[i];
	}
	cout<<endl;
	
	for(long long i=0;i<N;i++){
		if(i!=0)cout<<' ';
		cout<<b[i];
	}
	cout<<endl;
	
	
	
	
	return 0;
}
