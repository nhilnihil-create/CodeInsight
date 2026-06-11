#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <utility>
#include <string>

#define loop(n) for(ll i=0;i<n;i++)

using namespace std;

typedef long long int ll;

constexpr int maxn = 100;

int main() {
    int n,m,d[maxn + 1][maxn + 1],e[maxn + 1][maxn + 1];
    for(int i = 0;i < maxn + 1;i++) for(int j = 0;j < maxn + 1;j++) d[i][j] = e[i][j] = 10000;
    scanf("%d %d",&n,&m);
    for(int i = 0;i < m;i++) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        d[a][b] = d[b][a] = e[a][b] = e[b][a] = c;
    }
    for(int i = 1;i <= n;i++) {
        d[i][i] = e[i][i] = 0;
    }
    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) for(int k = 1;k <= n;k++)
        e[j][k] = min(e[j][k],e[j][i]+e[i][k]);

    int cnt = 0;
    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) if(d[i][j] != 10000 && d[i][j] > e[i][j]) cnt++;

    printf("%d",cnt/2);
}