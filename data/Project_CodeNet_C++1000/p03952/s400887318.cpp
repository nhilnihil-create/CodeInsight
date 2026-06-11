#include<cstdio>
using namespace std;
int n,m,x;
int main(){
	scanf("%d%d",&n,&x);m=(n<<1)-1;
	if(x==1||x==m) puts("No");else{
		puts("Yes");
		if(n==2) printf("1\n2\n3\n");else
		if(x==2)
		for (int i=1,j=1;i<=m;i++){
			if(i==n-2) printf("%d\n",m-1);else
			if(i==n-1) puts("1");else
			if(i==n) printf("%d\n",x);else
			if(i==n+1) printf("%d\n",m);else
			printf("%d\n",(++j)==x?++j:j);
		}
		else
		for (int i=1,j=2;i<=m;i++){
			if(i==n-2) puts("2");else
			if(i==n-1) printf("%d\n",m);else
			if(i==n) printf("%d\n",x);else
			if(i==n+1) puts("1");else
			printf("%d\n",(++j)==x?++j:j);
		}
	}
	return 0;
}