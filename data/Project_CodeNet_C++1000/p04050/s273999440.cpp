#include<cstdio>
#include<algorithm>
using namespace std;
inline char tc(void){
	static char fl[10000],*A=fl,*B=fl;
	return A==B&&(B=(A=fl)+fread(fl,1,10000,stdin),A==B)?EOF:*A++;
}
inline int read(void){
	int a=0;static char c;
	while((c=tc())<'0'||c>'9');
	while(c>='0'&&c<='9')a=a*10+c-'0',c=tc();
	return a;
}
int n,m,A[101],s;
int main(void){
	register int i;
	n=read(),m=read();
	for(i=1;i<=m;++i)
		A[i]=read(),s+=A[i]&1;
	if(s>2)
		return puts("Impossible"),0;
	if(s<=2){
		if(s>=1&&!(A[i]&1))	
			for(i=2;i<=m;++i)
				if(A[i]&1){
					swap(A[1],A[i]);
					break;
				}
		if(s==2&&!(A[m]&1))	
			for(i=2;i<m;++i)
				if(A[i]&1){
					swap(A[m],A[i]);
					break;
				}
	}
	for(i=1;i<=m;++i)
		printf("%d ",A[i]);
	putchar('\n');
	if(m==1){
		if(A[1]==1)
			printf("%d\n%d",1,1);
		else printf("%d\n%d %d",2,1,A[1]-1);
		return 0;
	}
	if(A[m]==1){
		printf("%d\n",m-1);
		printf("%d ",A[1]+1);
		for(i=2;i<m;++i)
			printf("%d ",A[i]);
		return 0;
	}
	printf("%d\n",m);
	printf("%d ",A[1]+1);
	for(i=2;i<m;++i)
		printf("%d ",A[i]);
	printf("%d ",A[m]-1);
	return 0;
}