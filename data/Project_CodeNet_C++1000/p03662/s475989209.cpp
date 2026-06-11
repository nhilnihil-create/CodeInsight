#include <string.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
#include <set>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
#define INF 0x3f3f3f3f
#define ESP 1e-8
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
const double PI = acos(-1.0);

#define N 100005
struct Edge{
    int from, to, next;
}e[N*2];
int head[N], ecnt, n;

void add(int idx, int to){
    e[ecnt].from=idx, e[ecnt].to=to;
    e[ecnt].next=head[idx], head[idx]=ecnt++;
}

int d[2][N], c;
void dfs(int idx, int pa, int len){
    d[c][idx] = len;
    int i = head[idx];
    while(i != -1){
        if(e[i].to != pa)
            dfs(e[i].to, idx, len+1);
        i = e[i].next;
    }
}

int main(){
    // FILE *fp = freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    int i, x, y;
    while(scanf("%d", &n) != EOF){
        ecnt = 0;
        memset(head, -1, sizeof(head));
        for(i = 1; i < n; i++){
            scanf("%d%d", &x, &y);
            add(x, y), add(y, x);
        }
        c = 0, dfs(1, 0, 0);
        c = 1, dfs(n, 0, 0);
        x = 0;
        for(i = 1; i <= n; i++)
            if(d[0][i] <= d[1][i])
                x++;
        if(x > n - x)
            printf("Fennec\n");
        else
            printf("Snuke\n");
    }

    // fclose(fp);
    return 0;
}