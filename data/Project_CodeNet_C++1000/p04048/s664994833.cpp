#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long ld;
ll read(){ll x;scanf("%lld",&x);return x;}
ll F(ll x,ll y){
	if(x%y==0){return 2*x-y;}
	return F(y,x%y)+2*(x/y)*y;
}
int main(){
	ll N=read(),X=read();
	printf("%lld\n",F(N-X,X)+N);
	return 0;	
} 