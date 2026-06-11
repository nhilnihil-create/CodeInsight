#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10;
int x[maxn],xx[maxn],w[maxn];
int k,l,r,s,t,n,m;
long long c;
inline int read(){
	int r=0,w=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){ if(ch=='-') w=-1;ch=getchar(); }
	while(ch>='0'&&ch<='9'){ r=r*10+ch-'0'; ch=getchar(); }
	return r*w;
}
int main(){
    n=read(),l=read(),t=read();
    for(int i=1;i<=n;i++)
        x[i]=read(),w[i]=read();
	for(int i=1;i<=n;i++){
        if (w[i]==2) w[i]=-1;
        r=x[i]+w[i]*t;
        if (r>0) (c+=r/l)%=n;
        else if (r<0) (c+=(r+1)/l-1)%=n;
        xx[i]=(r%l+l)%l;
    }
    sort(xx+1,xx+n+1);
    c=(c+n)%n;
    for(int i=c+1;i<=n;i++)
        printf("%d\n",xx[i]);
    for(int i=1;i<=c;i++) printf("%d\n",xx[i]);
}