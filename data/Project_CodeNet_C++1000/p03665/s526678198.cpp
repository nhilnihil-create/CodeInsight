#include <bits/stdc++.h>
using namespace std;

long long N,P,tmp,zero=0,one=0;

long long pangkat(long long a, long long b){
	long long hasil=1;
	for(int i=0; i<b; i++){
		hasil=hasil*a;
	}
	return hasil;
}

int main(){
	cin>>N>>P;
	for(int i=0; i<N; i++){
		cin>>tmp;
		if(tmp%2==0){
			zero++;
		}else{
			one++;
		}
	}
	if(one>1){
		cout<<pangkat(2,N-1)<<'\n';
	}else{
		if(P==0){
			cout<<pangkat(2,N)<<'\n';
		}else{
			cout<<0<<'\n';
		}
	}
}