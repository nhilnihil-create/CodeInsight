#include<cstdio>
long long N;
int a[410];
int main(){
	scanf("%lld",&N);N++;
	int*h=a+201,*t=h,n=0;
	int i=44;while(!(N>>i))i--;
	while(i--){
		*t++=++n;
		if(N>>i&1)*--h=++n;
	}
	printf("%d\n",n*2);
	for(int i=0;i<n*2;i++)printf("%d%c",i<n?h[i]:i-n+1," \n"[i==n*2-1]);
}