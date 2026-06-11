#include<cstdio>
using namespace std;
typedef long long LL;
LL n,x;
LL gcd(LL x,LL y){return y?gcd(y,x%y):x;}
int main(){
	scanf("%lld%lld",&n,&x);
	printf("%lld",3*(n-gcd(n,x)));
	return 0;
}