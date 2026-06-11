#include<bits/stdc++.h>
const int N=100007;
int n,m,as[N],ap=0,os[2],op=0,A[N],Ap=0,B[N],Bp=0;
void pA(int x){A[Ap++]=x;}
void pB(int x){if(x)B[Bp++]=x;}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0,x;i<m;++i){
		scanf("%d",&x);
		if(x&1){
			if(op==2)return puts("Impossible"),0;
			os[op++]=x;
		}else as[ap++]=x;
	}
	while(ap&&op<2)os[op++]=as[--ap];
	if(op==1){
		pA(os[0]);
		pB(1);
		pB(os[0]-1);
	}else{
		pA(os[0]);
		pB(os[0]-1);
		pB(2);
		for(int i=0;i<ap;++i){
			pA(as[i]);
			pB(as[i]);
		}
		pA(os[1]);
		pB(os[1]-1);
	}
	for(int i=0;i<Ap;++i)printf("%d ",A[i]);
	printf("\n%d\n",Bp);
	for(int i=0;i<Bp;++i)printf("%d ",B[i]);
	return 0;
}