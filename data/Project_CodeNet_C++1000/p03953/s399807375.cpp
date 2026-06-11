#include <bits/stdc++.h>
#define int long long
#define re register
#define inf 0x3f3f3f3f
#define mod 1000000007
using namespace std;
inline int read(){
	int x=0,w=0;char ch=getchar();
	while (!isdigit(ch))w|=ch=='-',ch=getchar();
	while (isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return w?-x:x;
}
int a[100007],c[100007],v[100007],t[100007],n;
inline void ksm(int p){
	while (p){
		if (p&1){
			for (int i=1;i<=n;++i)t[i]=c[v[i]];
			for (int i=1;i<=n;++i)c[i]=t[i];
		}
		for (int i=1;i<=n;++i)t[i]=v[v[i]];
		for (int i=1;i<=n;++i)v[i]=t[i];
		p>>=1;
	}
}
signed main(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read(),c[i]=a[i]-a[i-1],v[i]=i;
    int m=read(),k=read();
    for(int i=1;i<=m;i++){
        int x=read();
        swap(v[x],v[x+1]);
    }
    ksm(k);
    double sum=0;
	for (int i=1;i<=n;++i){
		sum+=c[i];
		printf("%.1lf\n",sum);
	}
	return 0;
}
