#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
int main() {
    
	ll pos=0 , i;
	
	cin>>i;
	
	ll t=(-1+sqrt(1+(8*i)))/2;
	
	((t*(t+1))/2)==i ? cout << t : cout << t+1 ; 
}