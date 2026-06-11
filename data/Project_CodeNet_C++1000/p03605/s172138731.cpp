#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n){
		if(n%10==9){
			cout<<"Yes";
			return 0;
		}
		n/=10;
	}
	cout<<"No";
}