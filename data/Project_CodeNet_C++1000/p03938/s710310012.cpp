#include<bits/stdc++.h>
using namespace std;
const int M=20005;
int A[M],B[M],p[M];
int n;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",p+i);
		A[i]=i*n;
		B[i]=(n-i+1)*n;
	}
	for(int i=2;i<=n;++i)
		A[p[i]]+=i-1;
	for(int i=1;i<=n;++i)
		printf("%d%c",A[i]," \n"[i==n]);
	for(int i=1;i<=n;++i)
		printf("%d%c",B[i]," \n"[i==n]);

	return 0;
}
