#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int main(){
	int n;scanf("%d",&n);
	int x=1;
	ll ans=0;
	rep(i,n){
		int a;scanf("%d",&a);
		if(a<x)continue;
		if(a==x){x++;continue;}
		ans+=(a-1)/x;
		if(i==0)x++;
	}
	cout<<ans<<endl;
}