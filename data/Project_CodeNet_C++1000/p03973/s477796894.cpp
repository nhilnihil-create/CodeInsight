#include<stdio.h>
#include<algorithm>
using namespace std;
int b[110000];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",b+i);
	long long ret=0;
	int sd=1;
	for(int i=0;i<a;i++){
		ret+=(b[i]-1)/sd;
		if((b[i]-1)/sd){
			b[i]=1;
		}
		sd=max(sd,b[i]+1);
	//	printf("%lld %d\n",ret,sd);
	}
	printf("%lld\n",ret);
}