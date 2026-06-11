#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 505;
const int Maxm = Maxn * Maxn;

int n;
int wr[Maxm];
vector <ii> seq;
int nd[Maxn];
int lft[Maxn];
int res[Maxm];

int main()
{
    scanf("%d", &n);
    priority_queue <ii> Q;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        if (wr[x]) { printf("No\n"); return 0; }
        wr[x] = i;
        Q.push(ii(i - x, i));
        nd[i] = i - 1;
    }
    int pnt = 0;
    for (int i = 1; i <= n * n; i++) {
        if (wr[i]) {
            res[i] = wr[i];
            if (nd[wr[i]] > 0) { printf("No\n"); return 0; }
            lft[wr[i]] = n - wr[i];
        } else {
            while (!Q.empty() && nd[Q.top().second] == 0) Q.pop();
            if (!Q.empty()) {
                ii p = Q.top(); Q.pop();
                res[i] = p.second;
                nd[p.second]--;
                p.first--;
                Q.push(p);
            } else {
                int oth = 1;
                while (oth <= n && lft[oth] == 0) oth++;
                if (oth > n) { printf("No\n"); return 0; }
                res[i] = oth;
                lft[oth]--;
            }
        }
    }
    printf("Yes\n");
    for (int i = 1; i <= n * n; i++)
        printf("%d%c", res[i], i + 1 <= n * n? ' ': '\n');
    return 0;
}
