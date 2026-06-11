#include <bits/stdc++.h>
using namespace std;
long long maxl(long long a,long long b){
	return a>b?a:b;
}
int main(){
	int n;
	cin>>n;
	long long x=1,y=1;
	for(int i=1;i<=n;i++){
		int a,b;
		cin>>a>>b;
		x=maxl((x-1)/a,(y-1)/b)*a+a;
		y=maxl((x-1)/a,(y-1)/b)*b+b;
	} 
	cout<<x+y<<endl;
}