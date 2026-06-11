#include<cstdio>
int n,m,nn,mm,i,j;
void put(int x){if (x>9) put(x/10);putchar(x%10+48);}
void write(int x){if (x<0) putchar('-'),x=-x;put(x);}
int main(){
	scanf("%d%d%d%d",&n,&m,&nn,&mm);
	if (n%nn==0&&m%mm==0){puts("No");return 0;}
	puts("Yes");
	int v=(1e9-1)/(nn*mm-1),k=-(nn*mm-1)*v-1;
	for (i=1;i<=n;i++,putchar('\n')) for (j=1;j<=m;j++)
		write(i%nn||j%mm?v:k),putchar(' ');
}