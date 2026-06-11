#include <bits/stdc++.h>

#define MAX_N 500
#define MAX_M 500

using namespace std;

int n, m, d;

int noui(int i, int j)
{
    return i + j - 1;
}

int nouj(int i, int j)
{
    return (n - 1 + m) - (i - j + m) + 1;
}

int cd[2][2] = {{1, 2},
                {3, 4}
};

int cod(int i, int j)
{
    int loci = (i / d + ((i % d) != 0)) % 2;
    int locj = (j / d + ((j % d) != 0)) % 2;

    //printf("AVEM %d %d  si codul %d %d\n", i, j, loci, locj);
//
    return cd[loci][locj];
}

char codul[] = {0, 'R', 'Y', 'G', 'B'};

char charul(int nr)
{
    return codul[nr];
}

int a[MAX_N + 1][MAX_M + 1];

int main()
{
    scanf("%d%d%d", &n, &m, &d);

    int i, j;
    for(i = 1; i <= n; i ++)
    {
        for(j = 1; j <= m; j ++)
        {
            a[i][j] = cod(noui(i, j), nouj(i, j));
        }
    }

    for(i = 1; i <= n; i ++)
    {
        for(j = 1; j <= m; j ++)
        {
            printf("%c", charul(a[i][j]));
        }

        printf("\n");
    }

    return 0;
}
