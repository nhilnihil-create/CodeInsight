#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=100010;
int n;
int a[N];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
inline int gcd(int x,int y) {return y?gcd(y,x%y):x;}
inline bool solve() {
    for(int i=1;i<=n;i++) {
	if(a[i]==1) return 0;
	if(a[i]&1) --a[i];
    }
    int g=a[1],t=0;
    for(int i=2;i<=n;i++) g=gcd(g,a[i]);
    for(int i=1;i<=n;i++) t+=!((a[i]/=g)&1);
    if(t&1) return 0;
    else if(n>t+1) return 1;
    return solve()^1;
}
int main() {
    int t=0;
    cin>>n;
    for(int i=1;i<=n;i++) a[i]=gi(),t+=!(a[i]&1);
    if(t&1) puts("First");
    else if(n>t+1) puts("Second");
    else puts(solve()?"First":"Second");
    return 0;
}