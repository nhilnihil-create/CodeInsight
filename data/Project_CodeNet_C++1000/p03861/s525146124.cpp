#include<bits/stdc++.h>
using namespace std;

int main(){
	long long a,b,x;
	cin>>a>>b>>x;
	long long k1 = a/x*x + (a%x?x:0);
	long long k2 = b/x*x;
	cout<<(k2-k1)/x+1;
}