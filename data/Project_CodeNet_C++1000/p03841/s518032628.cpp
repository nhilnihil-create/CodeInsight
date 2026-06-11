#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=510;
int a[N],id[N],w[N*N];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
inline bool cmp(const int &x,const int &y) {return a[x]<a[y];}
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) a[i]=gi(),id[i]=i;
    sort(id+1,id+1+n,cmp);
    for(int i=1;i<=n;i++) {
	int t=id[i],p=1;w[a[t]]=t;
	for(int j=1;j<t;j++) {
	    while(w[p]) ++p;
	    w[p]=t;
	}
	if(p>a[t]) return puts("No"),0;
    }
    for(int i=1;i<=n;i++) {
	int t=id[i],p=1;
	for(int j=t+1;j<=n;j++) {
	    while(w[p]) ++p;
	    if(p<a[t]) return puts("No"),0;
	    w[p]=t;
	}
    }
    puts("Yes");
    for(int i=1;i<=n*n;i++) printf("%d ",w[i]);
    return 0;
}
