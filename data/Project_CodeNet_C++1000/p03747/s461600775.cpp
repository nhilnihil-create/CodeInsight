#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int g[100010];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
int main() {
    int n,L,T;
    long long s=0;
    cin>>n>>L>>T;
    for(int i=0;i<n;i++) {
	int x=gi(),y=gi();
	if(y==1) {
	    g[i]=(x+T)%L;
	    if(T>=L-x) s+=(T-L+x)/L+1;
	}
	else {
	    g[i]=((x-T)%L+L)%L;
	    if(T>=x+1) s-=(T-x-1)/L+1;
	}
    }
    s=(s%n+n)%n,sort(g,g+n);
    for(int i=0;i<n;i++) printf("%d\n",g[(s+i)%n]);
    return 0;
}