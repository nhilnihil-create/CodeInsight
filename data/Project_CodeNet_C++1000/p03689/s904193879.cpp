#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll lim = 1000000000;
const int Maxn = 505;

int N, M, n, m;
int B[Maxn][Maxn];
ll st;

int main()
{
    scanf("%d %d %d %d", &N, &M, &n, &m);
    for (int i = 0; i < N; i += n)
        for (int j = 0; j < M; j += m)
            B[i][j] = lim - 1;
    for (int i = n - 1; i < N; i += n)
        for (int j = m - 1; j < M; j += m)
            B[i][j] = -lim;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            st += B[i][j];
    if (st <= 0) { printf("No\n"); return 0; }
    printf("Yes\n");
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            printf("%d%c", B[i][j], j + 1 < M? ' ': '\n');
    return 0;
}
