#include<cstdio>
using namespace std;
const int MAXN=3e5+5;
int N;
int A[MAXN];

bool Check(int Key){
	for(int i=0;i<N-1;i++){
		if( (A[N+i]>Key && A[N+i+1]>Key) || (A[N-i]>Key && A[N-i-1]>Key) ){
			return 0;
		}
		if( (A[N+i]<=Key && A[N+i+1]<=Key) || (A[N-i]<=Key && A[N-i-1]<=Key) ){
			return 1;
		}
	}
	return A[1]<=Key;
}

int BS(int L,int R){
	int Ans=0;
	while(L<=R){
		int Mid=(L+R)>>1;
		if(Check(Mid)){
			Ans=Mid;
			R=Mid-1;
		}else{
			L=Mid+1;
		}
	}
	return Ans;
}

int main(){
	
	scanf("%d",&N);
	
	for(int i=1;i<=2*N-1;i++){
		scanf("%d",&A[i]);
	}
	
	printf("%d\n",BS(1,2*N-1));
	
	return 0;
	
} 