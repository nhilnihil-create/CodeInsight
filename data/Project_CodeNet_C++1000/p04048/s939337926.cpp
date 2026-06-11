#include<bits/stdc++.h>
using namespace std;

long long a,b;

long long f(long long n,long long x){
		if(n%x==0)return (n<<1)-x;
		return 2*(n/x)*x+f(x,n%x);
	
}

int main(){
	cin>>a>>b;
	cout<<f(b,a-b)+a<<endl;
}