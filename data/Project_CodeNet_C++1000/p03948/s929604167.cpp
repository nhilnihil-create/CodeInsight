#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
int main() {
    int n,T,la=0,ans=0;
    cin>>n>>T;
    for(int i=1,j=1<<30;i<=n;i++) {
	int x=gi();
	if(la<x-j) la=x-j,ans=0;
	if(la==x-j) ++ans;
	j=min(j,x);
    }
    cout<<ans;
    return 0;
}