#include<cstdio>

struct edge {
    int from, to;
    int cost;
}; 

int n, m;
long d[1000];
bool jf[1000], jb[1000];
edge e[2000];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        e[i].from = a - 1;
        e[i].to = b - 1;
        e[i].cost = c;
    }
    
    jf[0] = true;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (jf[e[j].from]) jf[e[j].to] = true;
        }
    }
    jb[n - 1] = true;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (jb[e[j].to]) jb[e[j].from] = true;
        }
    }
    
    for (int i = 1; i < n; i++) d[i] = -1e18;
    bool update = true;
    int cnt = 0;
    while (update) {
        if (++cnt == n + 1) {
            printf("inf\n");
            return 0;
        }
        update = false;
        for (int i = 0; i < m; i++) {
            if (jf[e[i].from] && jb[e[i].to] && d[e[i].from] + e[i].cost > d[e[i].to]) {
                d[e[i].to] = d[e[i].from] + e[i].cost;
                update = true;
            }
        }
    }

    printf("%ld\n", d[n - 1]);
    return 0;
}
