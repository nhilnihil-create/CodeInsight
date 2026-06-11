#include <bits/stdc++.h>
using namespace std;

long long N,A,B;

int main(){
	cin>>N>>A>>B;
	long long totalA=A*(N-1)+B,totalB=A+(N-1)*B;
	if((N==1&&A!=B)||A>B){
		cout<<0<<'\n';
	}else{
		cout<<totalB-totalA+1<<'\n';
	}
}