#include<cstdio>
typedef long long ll;
ll n,a,b,c,d,i;
ll abs(ll x){
	return x>0?x:-x;
}
int main(){
	scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d);
	a*=2;b*=2;c*=2;d*=2;
	n--;
	for(i=1;i<=n;i++)
		if(a<b)
			a+=(c+d)/2;
		else
			a-=(c+d)/2;
	if(abs(a-b)<=n*(d-c)/2)
		printf("YES");
	else
		printf("NO");
}