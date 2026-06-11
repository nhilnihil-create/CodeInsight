#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define st first
#define nd second
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
template <class T> T read(T &a) {
    a=0;char x=getchar();bool f=0;
    for(;x<'0'||x>'9';x=getchar())f|=x=='-';
	for(;x>='0'&&x<='9';x=getchar())a=(a<<3)+(a<<1)+x-'0';
    if(f)a=-a;
    return a;
}
using namespace std;



int main() {
	LL n, x;
	read(n), read(x);
	LL gcd = __gcd(n, x);
	n /= gcd;
	cout << (n * 3 - 3) * gcd; 
    return 0;
}
