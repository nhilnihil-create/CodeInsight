#include<cstdio>
int N,M,A[110],a[110],b[110],n;
void ins(int x){if(x)b[n++]=x;}
int main(){
	scanf("%d%d",&N,&M);
	int os[2],oc=0;
	for(int i=0;i<M;i++){
		scanf("%d",A+i);
		if(A[i]%2){
			if(oc>1)return puts("Impossible"),0;
			os[oc++]=A[i];
		}
	}
	if(oc<2){
		a[0]=os[0];
		for(int i=0;i<M;i++)if(A[i]%2==0)a[oc++]=A[i];
		for(int i=0;i<M;i++)ins(a[i]-!i);
		ins(1);
	}
	else{
		a[0]=os[0];a[M-1]=os[--oc];
		for(int i=0;i<M;i++)if(A[i]%2==0)a[oc++]=A[i];
		for(int i=0;i<M;i++)ins(a[i]-!i+(i==M-1));
	}
	for(int i=0;i<M;i++)printf("%d%c",a[i]," \n"[i==M-1]);
	printf("%d\n",n);
	for(int i=0;i<n;i++)printf("%d%c",b[i]," \n"[i==n-1]);
}