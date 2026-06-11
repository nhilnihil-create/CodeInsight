#include<iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200100;

int head[N];
int cnt;
struct Edge{
    int v;
    int next;
};
Edge edge[N];
void add(int u, int v) {
    edge[cnt].v = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
    edge[cnt].v = u;
    edge[cnt].next = head[v];
    head[v] = cnt++;
}
int n;
int color[N];
bool vis[N];
int len;
bool f;
void dfs(int v, int l) {
    if(v == n) {
        len = l;
        f = true;
        return;
    }
    for(int i = head[v]; i != -1; i = edge[i].next) {
        if(!vis[edge[i].v]) vis[edge[i].v] = true, dfs(edge[i].v, l + 1);
        if(f) {
            if(l <= len / 2) color[v] = 1;
            else color[v] = -1;
            return;
        }
    }
}

void paint(int v, int cl) {
    for(int i = head[v]; i != -1; i = edge[i].next) {
        if(!color[edge[i].v]) {
            color[edge[i].v] = cl;
            paint(edge[i].v, cl);
        }
    }
}

int main() {
    cnt = 0;
    memset(head, -1, sizeof(head));
    int a, b;
    cin >> n;
    for(int i = 1; i < n; i++) {
        cin >> a >> b;
        add(a, b);
    }
    color[1] = 1; color[n] = -1;
    vis[1] = true;
    dfs(1, 0);
    for(int i = 1; i <= n; i++) {
        if(color[i]) paint(i, color[i]);
    }
    int fennec = 0, snuke = 0;
    for(int i = 1; i <= n; i++) {
        if(color[i] == 1) fennec++;
        else if(color[i] == -1) snuke++;
    }
    if(fennec > snuke) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
    return 0;
}
