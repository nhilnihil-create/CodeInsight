#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <utility>
#include <string>

#define loop(n) for(ll i=0;i<n;i++)

using namespace std;

typedef long long int ll;

constexpr int maxn = 40,maxc = 10;

int n,m[2],a[maxn+1][3],d[maxn+1][maxn*maxc+11][maxn*maxc+11];

int main() {
    scanf("%d %d %d",&n,&m[0],&m[1]);
    for(int i = 1;i <= n;i++) scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
    for(int i = 0;i <= n;i++) for(int j = 0;j <= maxn*maxc+10;j++) for(int k = 0;k <= maxn*maxc+10;k++) d[i][j][k] = INT32_MAX/2;
    d[0][0][0] = 0;
    for(int i = 1;i <= n;i++) for(int j = 0;j <= maxn*maxc;j++) for(int k = 0;k <= maxn*maxc;k++) {
        int s = j + a[i][0],t = k + a[i][1];
        d[i][s][t] = min(d[i][s][t],d[i-1][j][k]+a[i][2]);
        d[i][j][k] = min(d[i][j][k],d[i-1][j][k]);
    }
    int ret = INT32_MAX/2;
    for(int i = 1;max(m[0],m[1])*i <= maxn*maxc;i++) ret = min(ret,d[n][m[0]*i][m[1]*i]);
    printf("%d",ret == INT32_MAX/2 ? -1 : ret);
}