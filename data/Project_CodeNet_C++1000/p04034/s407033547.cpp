#include<bits/stdc++.h>
#define re register
#define inc(i,j,k) for(re int i=j;i<=k;i++)
using namespace std; 
const int N=1e5+5; 
inline int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while('0'<=ch&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,m,num[N],ans;
bool may[N];
int main(){
	n=read(),m=read();
	inc(i,1,n) num[i]=1;may[1]=1;
	inc(i,1,m){
		int x=read(),y=read();
		if(may[x]){
			if(num[x]==1) may[x]=0;
			may[y]=1;
		}
		num[x]--,num[y]++;
	}
	inc(i,1,n) if(may[i]) ans++;
	printf("%d\n",ans);
}