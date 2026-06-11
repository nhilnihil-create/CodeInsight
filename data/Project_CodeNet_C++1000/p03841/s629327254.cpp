#include<cstdio>
#include<algorithm>
int N,x[510],ls[510],rs[510],a[510*510],L[510];
bool cmp(int i,int j){return x[i]<x[j];}
bool solve(){
	for(int i=1;i<=N;i++)a[--x[i]]=i,L[i-1]=i;
	std::sort(L,L+N,cmp);
	for(int i=0;i<N;i++){
		ls[L[i]]=x[L[i]]-i;
		rs[L[i]]=N*N-N-x[L[i]]+i;
	}
	int pos=0;
	for(int t=0;t<2;t++){
		for(int*i=L;i<L+N;i++){
			for(int j=t?N-*i:*i-1;j--;){
				while(a[pos])pos++;
				if(t==(pos<x[*i]))return 0;
				a[pos++]=*i;
			}
		}
	}
	return 1;
}
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++)scanf("%d",x+i);
	if(solve()){
		puts("Yes");
		for(int i=0;i<N*N;i++)printf("%d%c",a[i]," \n"[i==N*N-1]);
	}
	else puts("No");
}