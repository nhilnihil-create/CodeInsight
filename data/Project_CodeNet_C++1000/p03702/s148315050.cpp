#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll n,a,b;
	ll h[100010];
	scanf("%lld%lld%lld",&n,&a,&b);
	for(int i=0;i<n;i++)scanf("%lld",&h[i]);
	
	ll l=1,r=1000000000;
	while(l<r){
		ll m=(l+r)/2;
		ll cnt=0;
		for(int i=0;i<n;i++){
			if(h[i]-m*b>0){
				cnt+=(h[i]-m*b+(a-b)-1)/(a-b);
			}
		}
		if(cnt<=m)r=m;
		else l=m+1;
	}
	cout<<l<<endl;
}

