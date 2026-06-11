#include<bits/stdc++.h>
using namespace std;

int main(){
	long long n,a,b;
	cin>>n>>a>>b;
	long long mn=(n-1)*a+b;
	long long mx=(n-1)*b+a;
	cout<<max(mx-mn+1,0ll);

}
//solved  problems for today:2
