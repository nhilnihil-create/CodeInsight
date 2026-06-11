#include <bits/stdc++.h>
using namespace std;

long long N,arr[300001];

int main(){
	cin>>N;
	for(int i=0; i<3*N; i++){
		cin>>arr[i];
	}
	sort(arr,arr+3*N);
	long long total=0,sum=0;
	for(int i=3*N-1; i>=0; i--){
		if((3*N-i)%2==0&&total<N){
			sum+=arr[i];
			total++;
		}
	}
	cout<<sum<<'\n';
}