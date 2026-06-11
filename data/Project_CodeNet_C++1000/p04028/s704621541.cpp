#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <bitset>
using namespace std;
typedef long long LL;
LL gi () {
    LL ret=0; char ch=getchar();
    while((ch<'0' || ch>'9') && ch!='-') ch=getchar();
    char c=ch=='-'?getchar():ch;
    while(c>='0' && c<='9') ret=ret*10+c-'0',c=getchar();
    return ch=='-'?-ret:ret;
}
const int mo = 1e9 + 7;
const int N = 5010;
const int inv2 = 500000004;
int n,t,f[N][N];
char s[N];
void upd (int &x,int y) {
    x += y; x -= (x >= mo ? mo : 0);
}
int main () {
    n = gi(); scanf("%s",s); t = strlen(s);
    f[0][0] = 1;
    for(int i=0;i<n;i+=1)
        for(int j=0;j<=i;j+=1) {
            int v = f[i][j]; upd(v,f[i][j]);
            if(j) upd(f[i+1][j-1],f[i][j]);
            else upd(f[i+1][j],f[i][j]);
            upd(f[i+1][j+1],v);
        }
    LL ans = f[n][t];
    for(int i=1;i<=t;i+=1) ans = ans * inv2 %mo;
    cout << ans;
    return 0;
}
