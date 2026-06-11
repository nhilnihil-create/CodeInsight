#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int N=100010;
bool w[N];
int a[N],b[N],p[N],id[N],v[N];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
int main() {
    int n,m;
    ll k,s=0;
    cin>>n;
    for(int i=1;i<=n;i++) a[i]=gi();
    for(int i=n;i>1;i--) a[i]-=a[i-1];
    for(int i=1;i<=n;i++) id[i]=i;
    cin>>m>>k;
    for(int i=1,x;i<=m;i++)
	x=gi(),swap(id[x],id[x+1]);
    for(int i=1;i<=n;i++)
	if(!w[i]) {
	    int x=i,tp=0;
	    while(!w[x]) w[x]=1,v[tp++]=x,x=id[x];
	    for(int j=0;j<tp;j++) b[v[j]]=a[v[(j+k)%tp]];
	}
    for(int i=1;i<=n;i++) printf("%lld\n",s+=b[i]);
    return 0;
}