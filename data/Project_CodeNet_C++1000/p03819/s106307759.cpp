#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int n,m,i,nxt,a[N];
int read(){
	char c=getchar();int k=0;for (;c<48||c>57;c=getchar());
	for (;c>47&&c<58;c=getchar()) k=(k<<3)+(k<<1)+c-48;return k;
}
void write(int x){if (x>9) write(x/10);putchar(x%10+48);}
int main(){
	for (m=read(),n=read();m--;){
		int l=read()-1,r=read();
		for (i=1;i<=l;i=nxt+1){
			nxt=min(l/(l/i),r/(r/i));
			if (l/i!=r/i) a[i]++,a[nxt+1]--;
		}
		a[l+1]++;a[r+1]--;
	}
	for (i=1;i<=n;i++) write(a[i]+=a[i-1]),putchar('\n');
}