#include <bits/stdc++.h>
using namespace std;

long long N,C,K,arr[100010];

int main(){
	cin>>N>>C>>K;
	for(long long i=0; i<N; i++)cin>>arr[i];
	sort(arr,arr+N);
	long long total=1,sol=1,maxim=arr[0]+K;
	for(long long i=1; i<N; i++){
		if(total==C||maxim<arr[i]){
			sol++; total=1; maxim=arr[i]+K;
		}else{
			total++;
		}
	}
	cout<<sol<<'\n';
}