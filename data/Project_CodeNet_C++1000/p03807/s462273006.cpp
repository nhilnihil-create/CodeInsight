#include <cstdio>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#pragma GCC optimize(2)
#include <immintrin.h>
#include <emmintrin.h>
using namespace std;
template<class code>inline code read(const code &a){
    code x=0;short w=0;char ch=0;
    while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
    while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return w?-x:x;
}
void pr(register int x){
	if(x<0){putchar('-');x=-x;}
	if(x>=10)pr(x/10);
	putchar(x%10+48);
}
int n,a;
long long sum;
int main(){
	ios::sync_with_stdio(false);
	n=read(n);
	for(register int i=1;i<=n;++i)a=read(a),sum+=a;
	if(sum%2)printf("NO");
	else printf("YES");
    return 0;
}
