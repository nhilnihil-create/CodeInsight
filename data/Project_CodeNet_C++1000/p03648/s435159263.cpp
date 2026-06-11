#include<cstdio>
#define LL long long
using namespace std;

LL k;
LL ans[100];

int main(){
	scanf("%lld",&k);
	LL i;
	LL t1=k/50;
	LL t2=k%50;
	for(i=1;i<=50;i++){
		ans[i]=i+t1-1;
	}
	for(i=50;i>=1 && t2;i--,t2--)
		ans[i]++;
	puts("50");
	for(i=1;i<=50;i++)
		printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}