#include<bits/stdc++.h>
using namespace std;
int M,N,m,n;
int main(){
	scanf("%d%d%d%d",&N,&M,&n,&m);
	// cout<<(1ll*n*m+1)*(M/m)*(N/n)<<endl;
	if((N%n==0)&&(M%m==0))puts("No");
	else{
		puts("Yes");
		for(int i=1;i<=N;++i){
			for(int j=1;j<=M;++j){
				printf("%d ",((i%n==0)&&(j%m==0))?-1000*m*n+1000-1:1000);
			}putchar('\n');
		}
	}
	return 0;
}