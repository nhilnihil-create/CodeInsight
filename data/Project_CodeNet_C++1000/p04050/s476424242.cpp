#include <bits/stdc++.h>

using namespace std;

//#define FILE_IO

bool cmp(int a, int b)
{
    return ( (a & 1) > (b & 1) );
}

int main()
{
    #ifdef FILE_IO
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    int N, M;
    int v[100005];
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= M; i++)
        scanf("%d", &v[i]);

    if(M == 1)
    {
        if(N == 1)
        {
            printf("1\n1\n1\n");
            return 0;
        }
        printf("%d\n", v[1]);
        printf("%d\n", 2);
        printf("%d %d\n", 1, N - 1);
        return 0;
    }

    for(int i = 1; i <= M; i++)
        if(v[i] % 2 == 1)
        {
            swap(v[i], v[1]);
            break;
        }
    for(int i = 2; i <= M; i++)
        if(v[i] % 2 == 1)
        {
            swap(v[i], v[M]);
            break;
        }
    for(int i = 2; i < M; i++)
        if(v[i] % 2 == 1)
        {
            printf("Impossible\n");
            return 0;
        }

    for(int i = 1; i <= M; i++)
        printf("%d ", v[i]);
    printf("\n");

    vector <int> r;
    r.push_back(v[1] - 1);
    for(int i = 2; i < M; i++)
        r.push_back(v[i]);
    r.push_back(v[M] + 1);
    for(int i = 0; i < (int)r.size(); i++)
        if(!r[i])
        {
            r.erase(r.begin() + i);
            i--;
        }

    printf("%d\n", (int)r.size());
    for(auto x: r)
        printf("%d ", x);

    return 0;
}
