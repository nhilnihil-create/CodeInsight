#include<cstdio>
using namespace std;
long long int base[40];
int num[40]={0};
int s[200]={0};
int main(){
	long long int N;
	scanf("%lld",&N);
    base[0]=1;
    for(int i=1;i<40;i++){
    	base[i]=base[i-1]*2;
	}
	int k=39;
	while(N>0){
		while(N<base[k]) k--;
		num[k]=1;
		N=N-base[k];
	}
	for(k=39;k>=0;k--){
		if(num[k]!=0) break;
	}
	int length=2*k+2;
	for(int i=0;i<k;i++){
		if(num[i]!=0) length+=2;
	}
	printf("%d\n",length);
	for(int i=0;i<k;i++){
		if(num[i]!=0) printf("%d ",k+i+2);
		printf("%d ",i+1);
	}
	for(int i=0;i<k;i++){
		printf("%d ",i+1);
	}
	printf("%d %d",k+1,k+1);
	for(int i=k-1;i>=0;i--){
		if(num[i]!=0) printf(" %d",k+i+2);
	}
	return 0;
}