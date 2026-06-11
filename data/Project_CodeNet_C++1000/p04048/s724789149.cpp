#include <bits/stdc++.h>
#define li long long int
using namespace std;
li gcd(li a,li b){
    if(a==0)
    return b;
    return gcd(b%a,a);
}
int main() {
	li n,x;
	cin>>n>>x;
	
	cout<<3*(n-gcd(n,x))<<endl;
	
	return 0;
}
