#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int A[101],B[101];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),o=0;
	for(int i=1;i<=m;++i)A[i]=gi();
	if(n==1)return printf("1\n1\n1\n"),0;
	if(m==1)printf("%d\n2\n%d 1\n",A[1],A[1]-1);
	else{
		for(int i=1;i<=m;++i)
			if(A[i]&1){
				++o;
				if(o==1)std::swap(A[i],A[1]);
				else if(i<m&&(A[m]&1))o=10000000;
				else std::swap(A[i],A[m]),o-=i<m;
			}
		if(o>2)return puts("Impossible"),0;
		for(int i=1;i<=m;++i)printf("%d ",A[i]);
		puts("");
		printf("%d\n",m-(A[m]==1));
		printf("%d ",A[1]+1);
		for(int i=2;i<=m;++i)if(i<m||A[i]>1)printf("%d ",A[i]-(i==m));
	}
	return 0;
}
