#include <bits/stdc++.h>
using namespace std;
#define rint register int
inline int rf(){int r;int s=0,c;for(;!isdigit(c=getchar());s=c);for(r=c^48;isdigit(c=getchar());(r*=10)+=c^48);return s^45?r:-r;}
int a[100005], n; bool W(int i){bool U = (a[i+1]-i)&1, R = 0; for(rint j = i+1; j <= n && a[j]>i; R ^= 1, j++); return U&R;}
int main(){n = rf(); generate(a+1,a+n+1,rf); sort(a+1,a+n+1,greater<int>()); for(rint i = 2; i <= n+1; i++) if(a[i]<i) return puts(W(i-2)?"Second":"First"),0;}