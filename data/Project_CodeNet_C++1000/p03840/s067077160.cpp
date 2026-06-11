#include<iostream>
#include<cstdio>
using namespace std;
long long a,b,c,d,e,f,g;
inline long long max(long long a,long long b){
	return a>b?a:b;
}
int main() {
	scanf("%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f,&g);
	printf("%lld\n",b+max(a/2*2+d/2*2+e/2*2+3*(a%2&&d%2&&e%2),3*(a>0&&d>0&&e>0)+(a-1)/2*2+(d-1)/2*2+(e-1)/2*2));
	return 0;
}