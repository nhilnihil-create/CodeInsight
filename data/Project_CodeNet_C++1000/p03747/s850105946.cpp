#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int n,L,T,i,a[N];long long cnt;
int read(){
	char c=getchar();int k=0;for (;c<48||c>57;c=getchar());
	for (;c>47&&c<58;c=getchar()) k=(k<<3)+(k<<1)+c-48;return k;
}
void write(int x){if (x>9) write(x/10);putchar(x%10+48);}
int main(){
	n=read();L=read();T=read();
	for (i=0;i<n;i++){
		int x=read(),k=read();
		x+=k==1?T:-T;
		cnt+=x/L;x%=L;
		if (x<0) x+=L,cnt--;
		a[i]=x;
	}
	sort(a,a+n);cnt=(cnt%n+n)%n;
	for (i=0;i<n;i++) write(a[(i+cnt)%n]),putchar('\n');
}