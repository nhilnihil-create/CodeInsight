#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int n,i,a[N],d[N],v[N];
int read(){
	char c=getchar();int k=0;for (;c<48||c>57;c=getchar());
	for (;c>47&&c<58;c=getchar()) k=(k<<3)+(k<<1)+c-48;return k;
}
int main(){
	for (n=read(),i=1;i<=n;i++) a[i]=read()-1;
	sort(a+1,a+n+1);a[0]=-1;
	for (i=1;i<=n;i++){
		int px=a[i-1]+i,dx=d[i-1]==px-1?v[i-1]:0;
		int rx=((a[i]-a[i-1])&1)^1;
		d[i]=px;v[i]=!dx||!rx?1:0;
	}
	for (i=1;d[i]<n;i++);
	int res=d[i]==n?v[i]:((d[i]-n)&1)^1;
	puts(res?"First":"Second");
}