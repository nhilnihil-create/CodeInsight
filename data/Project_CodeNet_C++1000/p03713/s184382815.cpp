#include <bits/stdc++.h>
using namespace std;

int main(){
	long long H,W;
	cin >> H >> W;

	long long ans=1e9;
	if(W%3==0)	ans=0;
	else	ans=min(ans,H);
	if(H%3==0)	ans=0;
	else ans=min(ans,W);

	for(int i=1;i<H;i++){
		long long a=i*W;
		long long b,c;
		if(W%2==0){
			b=(H-i)*(W/2);
			c=b;
		}
		else{
			b=(H-i)*(W/2);
			c=(H-i)*((W+1)/2);
		}
		long long mi=min({a,b,c});
		long long ma=max({a,b,c});
		ans=min(ans,ma-mi);
	}
	for(int i=1;i<W;i++){
		long long a=i*H;
		long long b,c;
		if(H%2==0){
			b=(W-i)*(H/2);
			c=b;
		}
		else{
			b=(W-i)*(H/2);
			c=(W-i)*((H+1)/2);
		}
		long long mi=min({a,b,c});
		long long ma=max({a,b,c});
		ans=min(ans,ma-mi);
	}
	cout << ans << endl;

	return 0;
}
