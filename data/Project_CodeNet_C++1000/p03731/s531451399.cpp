#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
using namespace std;

int main(){
	long long N,T;
	cin >> N >> T;
	vector<long long> t(N,0);
	long long sum=0;
	for(long long i=0;i<N;i++){
		cin >> t[i];
		
		if(i==0){
			sum+=0;
		}
		
		if(i>=1){
			if((t[i]-t[i-1])<T){
				sum+=t[i]-t[i-1];
			}else{
				sum+=T;
			}
		}
		
	}
	sum+=T;
	cout << sum << endl;
	return 0;
}
