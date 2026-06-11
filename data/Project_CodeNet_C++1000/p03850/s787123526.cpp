#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=100010;
long long f[N][3];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
int main() {
    int n;
    char c='+';
    cin>>n;
    f[0][0]=0,f[0][1]=f[0][2]=-1LL<<60;
    for(int i=1;i<=n;i++) {
	int x=gi();
	if(c=='+') {
	    f[i][0]=f[i-1][0]+x;
	    f[i][1]=f[i-1][1]-x;
	    f[i][2]=f[i-1][2]+x;
	}
	else {
	    f[i][0]=f[i-1][0]-x;
	    f[i][1]=max(f[i-1][1]+x,f[i-1][0]-x);
	    f[i][2]=max(f[i-1][2]-x,f[i-1][1]+x);
	}
	if(i<n) c=getchar();
	f[i][1]=max(f[i][1],f[i][2]);
	f[i][0]=max(f[i][0],f[i][1]);
    }
    cout<<f[n][0];
    return 0;
}