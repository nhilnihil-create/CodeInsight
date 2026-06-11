#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,x,a,b,c,d;
int main(){
	scanf("%d%d%d%d%d%d%d",&a,&b,&x,&c,&d,&x,&x);
	if(a&&c&&d)n=!(a%2==c%2&&c%2==d%2);
	else n=a%2+c%2+d%2;
	printf("%lld\n",1ll*a+b+c+d-n);
}
