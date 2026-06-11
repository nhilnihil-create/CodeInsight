#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    int N, M;
    cin >> N >> M;

    vector<bool> ok1(N, false);
    vector<bool> ok2(N, false);

    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        if (a == 1)
        {
            ok1[b - 1] = true;
        }
        if (b == N)
        {
            ok2[a - 1] = true;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (ok1[i] && ok2[i])
        {
            printf("POSSIBLE\n");
            return (0);
        }
    }
    printf("IMPOSSIBLE\n");
    return (0);
}