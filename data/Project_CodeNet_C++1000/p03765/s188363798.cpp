#include<cstdio>
const int N=1e5+5;
int q,A[N],B[N],l,r,L,R;char s[N];
int main(){
	scanf("%s",s+1);for(int i=1;s[i];++i)A[i]=A[i-1]+s[i]-64;
	scanf("%s",s+1);for(int i=1;s[i];++i)B[i]=B[i-1]+s[i]-64;
	for(scanf("%d",&q);q--;)scanf("%d%d%d%d",&l,&r,&L,&R),puts((A[r]-A[l-1])%3==(B[R]-B[L-1])%3?"YES":"NO");
	return 0;
}