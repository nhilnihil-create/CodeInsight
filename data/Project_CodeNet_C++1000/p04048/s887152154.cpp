#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int n,x,temp;
	cin>>n>>x;
	x=min(x,n-1);
	long long int res=n;
	n=n-x;
	while(n!=x){
		if(x<n){
			temp=n/x;
			if(n%x==0){
				res+=(2*x*(temp-1)+x);
				cout<<res;return 0;
			}
			res+=2*x*temp;
			n-=temp*x;
		}else{
			temp=x/n;
			if(x%n==0){
				res+=(2*n*(temp-1)+n);
				cout<<res;return 0;
			}
			res+=2*n*temp;
			x-=n*temp;
		}
	}
	cout<<res+n;return 0;
}