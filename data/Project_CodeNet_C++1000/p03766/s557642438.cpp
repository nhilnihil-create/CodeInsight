#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5,P=1e9+7;
int n,a,b,A[4][4]={0,1,0,0,P-1,0,1,0,P-1,0,2,0,0,0,P-1,1},R[4][4]={1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1},B[4]={1,1,2,P-1},C[4],t[4][4];
inline void mult(int a[4][4],int b[4][4],int c[4][4]){
	for(int i=0;i<4;i++)for(int j=0;j<4;j++){unsigned long long w=0;for(int k=0;k<4;k++)w+=(ll)a[i][k]*b[k][j];t[i][j]=w%P;}
	memcpy(c,t,sizeof(t));
}
int main(){
	scanf("%d",&n);
	if(n<=2)printf("%d\n",n*n),exit(0);
	a=((ll)n*n+1)%P;b=n;n-=3;
	while(n){if(n&1)mult(R,A,R);mult(A,A,A);n>>=1;}
	for(int i=0;i<4;i++)for(int j=0;j<4;j++)C[i]=(C[i]+(ll)B[j]*R[i][j])%P;
	printf("%d\n",((C[3]+(ll)a*C[2]-C[1]-(ll)C[0]*b)%P+P)%P);
	return 0;
}