#include<cstdio>
int N,A[100010];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
bool calc(){
	bool s=0;
	int o=0;
	for(int i=0;i<N;i++)if(A[i]%2)o++;
	if(!o){
		for(int i=0;i<N;i++)A[i]/=2;
		return calc();
	}
	if(o==1&&N%2==1){
		int g=0;
		for(int i=0;i<N;i++)g=gcd(g,A[i]);
		for(int i=0;i<N;i++){
			if(A[i]==g)return 0;
			if(A[i]%2)A[i]-=g;
		}
		return!calc();
	}
	for(int i=0;i<N;i++)s^=(A[i]+1)%2;
	return s;
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",A+i);
	puts(calc()?"First":"Second");
}