#include<bits/stdc++.h>
using namespace std;
long long n,x;
long long ans;
void dg(long long x,long long y){
	if(x>y) swap(x,y);
	ans+=(y/x)*x*2;
	if(y%x==0){
		ans-=x;
		return;
	}
	dg(x,y%x);
}
int main(){
	cin>>n>>x;
	ans+=n;
	dg(x,n-x);
	cout<<ans;
	return 0;
}