#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
	ll a,b,c,mn;
	scanf("%lld%lld%lld",&a,&b,&c);
	
	if(c%2==0) mn=0;
	else mn=a*b;
	
	if(b%2==0) mn=0;
	else mn=min(mn,a*c);
	
	if(a%2==0) mn=0;
	else mn=min(mn,b*c);
	printf("%lld",mn);
	return 0;
	
}