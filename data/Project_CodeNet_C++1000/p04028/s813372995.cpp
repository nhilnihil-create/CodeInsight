#include <bits/stdc++.h>

using namespace std;

int N,L;
char s[5010];
const int MOD = 1e9 + 7;
typedef long long LL;
LL f[5010][5010];

void upd(LL &x,LL y)
{
    x = (x + y) % MOD;
}

int main()
{
    scanf("%d",&N);
    scanf("%s",s);
    L = strlen(s);
    f[0][0] = 1;
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<=i;j++)
        {
            upd(f[i+1][j+1],2LL*f[i][j]);
            upd(f[i+1][max(0,j-1)],f[i][j]);
        }
    }
    LL ans = f[N][L], rev = (MOD + 1) / 2;
    for (int i=1;i<=L;i++) ans = ans * rev % MOD;
    printf("%lld\n",ans);
}
