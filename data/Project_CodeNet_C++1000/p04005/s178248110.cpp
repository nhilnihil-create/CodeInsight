#include<iostream>
#include<cmath>
using namespace std;
int main() {
	long long a,b,c;
	cin>>a>>b>>c;
	if(a%2==0||b%2==0||c%2==0){
		cout<<0;
	}
	else{
		long long x=max(max(a,b),c);
		if(x==a){
			cout<<b*c;
		}
		else if(x==b){
			cout<<a*c;
		}
		else if(x==c){
			cout<<a*b;
		} 
	}
	return 0;
}