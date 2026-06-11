#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=5010,Mo=1000000007;
char s[N];
int f[N][N];
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
    scanf("%d%s",&n,s+1);
    m=strlen(s+1);
    f[0][0]=1;
    for(int i=1;i<=n;i++) {
	f[i][0]=f[i][1]=f[i-1][0];
	for(int j=1;j<=i;j++) {
	    f[i][j-1]=(f[i][j-1]+2LL*f[i-1][j])%Mo;
	    f[i][j+1]=(f[i][j+1]+f[i-1][j])%Mo;
	}
    }
    cout<<f[n][m];
    return 0;
}