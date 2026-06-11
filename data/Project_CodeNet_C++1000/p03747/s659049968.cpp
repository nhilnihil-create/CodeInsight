#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 2;

int n, m, k, a[N], dir[N], b[N];

inline int Collide(int i, int j)
{
    if (dir[i] == dir[j]) return false;
    if (dir[i] == -1) swap(i, j);
    int dist = (a[j] - a[i] + m) % m;
    if (k * 2 < dist) return 0;
    else return 1 + (k * 2 - dist) / m;
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d", &a[i], &dir[i]);
        dir[i] = (dir[i] == 1 ? 1 : -1);
        b[i] = ((a[i] + dir[i] * k) % m + m) % m;
    }
    sort(b, b + n);
    int rot = lower_bound(b, b + n, ((a[0] + dir[0] * k) % m + m) % m) - b;

    if (rot + 1 < n && b[rot] == b[rot + 1] && dir[0] == 1)                // special case: two ants have same position after T seconds
        ++rot;

    for (int i = 1; i < n; ++i)
    {
        rot += Collide(0, i) * -dir[0];
        rot = (rot % n + n) % n;
    }
    rotate(b, b + rot, b + n);
    for (int i = 0; i < n; ++i)
        printf("%d\n", b[i]);
    return 0;
}
