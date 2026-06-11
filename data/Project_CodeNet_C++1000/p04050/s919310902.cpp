#include<cstdio>
const int N=105;
int n,i,dn,d[3],an,a[N];
int read(){
	char c=getchar();int k=0;for (;c<48||c>57;c=getchar());
	for (;c>47&&c<58;c=getchar()) k=(k<<3)+(k<<1)+c-48;return k;
}
void write(int x){if (x>9) write(x/10);putchar(x%10+48);}
int main(){
	read();n=read();
	for (i=1;i<=n;i++){
		int x=read();
		if (x&1){
			d[++dn]=x;
			if (dn>2){
				puts("Impossible");
				return 0;
			}
		}
		else a[++an]=x;
	}
	int lt=1;
	if (dn) a[lt=0]=d[1];
	if (dn==2) a[++an]=d[2];
	for (i=lt;i<=an;i++)
		write(a[i]),putchar(' ');
	putchar('\n');
	if (n==1) an++;
	a[lt]--;a[an]++;
	write(a[0]>0?an+1:an);putchar('\n');
	for (i=a[0]>0?0:1;i<=an;i++)
		write(a[i]),putchar(' ');
}