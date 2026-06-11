/*  AtCoder Grand Contest 017. Problem D, by Abreto<m@abreto.net>. */
#include <cstdio>
#include <vector>

using namespace std;

#define MAXN    100001

int N;
vector<int> conj[MAXN];
int visited[MAXN];

int sg(int id)
{
    int ret = 0;
    visited[id] = 1;
    for(auto p : conj[id])
        if(!visited[p])
            ret ^= sg(p)+1;
    return ret;
}

int main(void)
{
    int i = 0;
    int xi = 0, yi = 0;

    scanf("%d", &N);
    for(i = 1;i < N;++i)
    {
        scanf("%d%d", &xi, &yi);
        conj[xi].push_back(yi);
        conj[yi].push_back(xi);
    }
    printf("%s\n", (0==sg(1))?"Bob":"Alice");

    return 0;
}
