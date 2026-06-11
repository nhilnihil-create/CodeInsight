#include <iostream>
#include<vector>
using namespace std;

int main() {
	long long k;cin>>k;
	long long div=k/50;
	long long mod=k%50;
	cout<<50<<endl;
	long long num=49+div;
	for(int i=0;i<mod;i++){
		cout<<num+50-mod+1<<' ';
	}
	for(int i=mod;i<50;i++){
		cout<<num-mod<<' ';
	}
	cout<<endl;
	return 0;
}
