#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000

#define Edge pair<long long,int>


		


int main(){
	
	long long N,X;
	cin>>N>>X;
	
	long long a = X,b = N-X;
	
	long long ans = a+b;
	
	while(true){
		if(a>b){
			if(a%b==0){
				ans += 2*a-b;
				break;
			}
			
			
			long long k = a-b;
			long long n = (k+b-1)/b;
			ans += n*2*b;
			a -= n*b;
		}
		else{
			if(b%a==0){
				ans += 2*b-a;
				break;
			}
			
			
			long long k = b-a;
			long long n = (k+a-1)/a;
			ans += n*2*a;
			
			b -= n*a;
		}
	}
	
	cout<<ans<<endl;
	
	
	return 0;
}
