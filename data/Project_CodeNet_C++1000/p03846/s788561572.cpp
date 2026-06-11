#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath> 
#define ll long long
 
ll MOD=1e9+7;
ll a[100005];
using namespace std;
 
int main(){
	ll n;
	cin>>n;
	
	ll flag=1;//flag 
	ll ans=1;
	
	if(n%2==0){ // even number 
	
		for(ll i=0;i<n;i++){
			ll x;
			cin>>x;
			a[x]++;//a[7]++
			
			// give data x error 
			if(x>=n || x%2==0 || a[x]>2){ 
				flag=0;
				cout<<"0"<<endl;
				break;
			}
			
			//The correct situation 
			if(a[x]==1)
				ans=ans*2%MOD; // a * b %c == a%c * b%c 
		}
	} 
	
	else{ //odd 
	
		for(ll i=0;i<n;i++){
			ll x;
			cin>>x;
			a[x]++;
			
			// give data x error 
			if(x>=n || x%2==1 || a[0]>1 ||a[x]>2){
				flag=0;
				cout<<"0"<<endl;
				break;
			}
			
			//The correct situation
			if(x!=0 && a[x]==1)
				ans=ans*2%MOD;
		}
	}
	
	if(flag)
		cout<<ans<<endl;
	return 0;
}