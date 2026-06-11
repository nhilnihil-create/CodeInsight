#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	int t;
	cin>>t;
	while(t--){
		long long  c,b,sum = 0 ;
		
		cin>>c>>b;
		
		for(int i = 0 ; i < n ; i++){
			if(i==c-1){
				sum+=b;
			}
			else
				sum+=a[i];
		}
		cout<<sum<<endl;
	}
	
}