#include<stdio.h>
#include<algorithm>
using namespace std;
long long c[110000];
long long d[110000];
 
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++)scanf("%lld",c+i);
	for(int i=0;i<b;i++)scanf("%lld",d+i);
	std::sort(c,c+a);
	std::sort(d,d+b);
	long long ret=0;
	int H=a;
	int W=b;
	int ai=0;
	int bi=0;
	for(int i=0;i<a+b;i++){
		if(ai<a&&(bi==b||c[ai]<d[bi])){
			ret+=(c[ai]*(b+1-bi));
			ai++;
		}else{
			ret+=(d[bi]*(a+1-ai));
			bi++;
		}
	}
	printf("%lld\n",ret);
}