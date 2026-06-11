#include<bits/stdc++.h>
#define re register
#define inc(i,j,k) for(re int i=j;i<=k;i++)
#define dec(i,j,k) for(re int i=j;i>=k;i--)
using namespace std;
const int N=1e5+5; 
inline int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while('0'<=ch&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,k,p,l[N],ans[N];
int main(){
	n=read(),k=read();
	inc(i,1,n) l[i]=read();
	inc(i,1,n-1){
		if(l[i]+l[i+1]>=k){
			p=i;
			break;
		}
	}
	if(!p) return puts("Impossible"),0;
	puts("Possible");
	inc(i,1,p-1) printf("%d\n",i);
	dec(i,n-1,p+1) printf("%d\n",i);
	printf("%d\n",p); 
}