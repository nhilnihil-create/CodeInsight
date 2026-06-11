#include<bits/stdc++.h>
using namespace std;
long long expo(long long a,long long b){
    if(b==0)return 1;
    long long temp = expo(a,b/2);
    temp = temp*temp;
    if(b%2!=0)temp*=a;
    return temp;
}
int main(){
	int n,p;
	cin>>n>>p;
	long long e=0,o=0;
	for(int i=0,a;i<n;i++){
		cin>>a;
		if(a%2)o++;
		else e++;
	}
	long long ans=1;
	if(p%2){
		//odd
		//odd number of odd values
		//any number of even values
		if(o==0){
			ans=0;
		}
		else{
			ans = ans*expo(2,o-1);
			ans = ans*expo(2,e);
		}
	}
	else{
		//even 
		ans = ans*(expo(2,e));
		if(o!=0)ans= ans*expo(2,o-1); 
	}
	cout<<ans;
}