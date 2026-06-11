#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAXN 100000
#define rint register int
#define gc() getchar()
inline int read(rint ans = 0, rint sgn = ' ', rint ch = gc())
{
	for(; ch < '0' || ch > '9'; sgn = ch, ch = gc());
	for(; ch >='0' && ch <='9';(ans*=10)+=ch-'0', ch = gc());
	return sgn-'-'?ans:-ans;
}
int a[MAXN+5], n;
inline int GCD(int a, int b){return b ? GCD(b,a%b) : a;} 
bool Calc()
{
	int even = 0; bool one = false, sum = 0;
	for(rint i = 1; i <= n; sum ^= (a[i]^1)&1, even += !(a[i]&1), one |= a[i] == 1, i++);
	if(one) return sum; if(even&1) return 1; if(!(even&1) && even < n-1) return 0;
	int g = 0; for(rint i = 1; i <= n; a[i] -= a[i]&1, g = GCD(g,a[i]), i++);
	for(rint i = 1; i <= n; a[i++] /= g); return Calc()^1;
}
int main(){n = read(); for(rint i = 1; i <= n; a[i++] = read()); puts(Calc()?"First":"Second"); return 0;}