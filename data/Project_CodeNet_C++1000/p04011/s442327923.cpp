#include<bits/stdc++.h>
using namespace std;

#define ll long long int

	
	
int main(){
	
	int n,k,x,y;
	cin>>n>>k>>x>>y;
	int ans= 0;
	if( n > k){
			ans += x * k;
			ans += abs(n-k) * y;
		}else{
			
			ans += x * n;
			}
	cout<<ans<<endl;
}
