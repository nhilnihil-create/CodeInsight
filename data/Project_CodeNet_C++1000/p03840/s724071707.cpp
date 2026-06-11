#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000


int main(){
	long long a,b,c,d,e,f,g;
	cin>>a>>b>>c>>d>>e>>f>>g;
	
	long long ans = 0;
	
	ans += b*2;
	
	long long x = 0;
	
	x += 4*(a/2);
	
	x += 4*(d/2);
	
	x += 4*(e/2);
	
	if(a%2&&d%2&&e%2)x+=6;
	
	long long y = 0;
	if(a&&d&&e){
		y+=6;
		a--;d--;e--;
	}
	
	y+=4*(a/2);
	y+=4*(d/2);
	y+=4*(e/2);
	
	ans += max(x,y);
	
	cout<<ans/2<<endl;
	
	
	
	return 0;
}
