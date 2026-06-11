#include<bits/stdc++.h>
#define re register
#define inc(i,j,k) for(re int i=j;i<=k;i++)
using namespace std;
const int N=205;
inline int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while('0'<=ch&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,l[N],ans;
int main(){
	n=read();
	inc(i,1,2*n) l[i]=read();
	sort(l+1,l+1+2*n);
	inc(i,1,n) ans+=l[2*i-1];
	printf("%d",ans); 
}