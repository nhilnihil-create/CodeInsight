#include<bits/stdc++.h>
const int MN=100000+5;
using namespace std;
typedef long long ll;
template<typename T>T&IN(T&in){
	in=0;char c=getchar();int f=1;
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))in=in*10+c-'0',c=getchar();
	in*=f;return in;
}
int n,m;
int a[MN],b[MN],c[MN];
void input(){
	IN(n),IN(m);
	for(int i=1;i<=m;++i){
		IN(a[i]);
		if(a[i]%2)b[++b[0]]=a[i];
	}
	if(m==1&&a[1]!=1)return printf("%d\n%d\n%d %d",a[1],2,a[1]-1,1),void();
	if(b[0]>2)return puts("Impossible"),void();
	if(b[0])printf("%d ",b[b[0]]),c[++c[0]]=b[b[0]]+1;
	else c[++c[0]]=1;
	for(int i=1;i<=m;++i)if(a[i]%2==0)printf("%d ",a[i]),c[++c[0]]=a[i];
	if(b[0]==2)printf("%d\n",b[1]),c[++c[0]]=b[1]-1;
	else c[c[0]]--,puts("");
	while(!c[c[0]]&&c[0]>1)c[0]--;
	int s=0;
	for(int i=1;i<=c[0];++i)s+=c[i];
	if(s!=n)c[++c[0]]=1;
	printf("%d\n",c[0]);
	for(int i=1;i<=c[0];++i)printf("%d ",c[i]);
}
int main(){
	input();
	return 0;
}