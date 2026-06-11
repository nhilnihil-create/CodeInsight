#include<cstdio>
const int MaxN=100010;
int N,A[MaxN];
long long S[MaxN];
char op[MaxN];
void cmax(long long&a,long long b){b>a?a=b:1;}
int main(){
	scanf("%d%d",&N,A);
	for(int i=1;i<N;i++)scanf("%s%d",op+i,A+i);
	long long ans=0,cur=0;
	for(int i=0;i<N;i++){
		S[i+1]=S[i]+A[i];
		ans+=op[i]=='-'?-A[i]:A[i];
	}
	for(int i=0,j;i<N;i++){
		if(op[i]=='-'){
			for(j=i+1;j<N&&op[j]!='-';j++);
			cmax(ans,cur+S[N]-S[j]*2+S[i]);
			cur-=A[i];
		}
		else cur+=A[i];
	}
	printf("%lld\n",ans);
}