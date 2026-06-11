#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5+10;

int n, m;
vector<int> graph[maxn];
bool bio[maxn];
deque<int> path;

void dfs1(int pos) {
    path.push_front(pos);
    bio[pos] = true;
    for (int i = 0; i < graph[pos].size(); i++) {
        int tren = graph[pos][i];
        if (!bio[tren]) {
            dfs1(tren);
            break;
        }
    }
}

void dfs2(int pos) {
    path.push_back(pos);
    bio[pos] = true;
    for (int i = 0; i < graph[pos].size(); i++) {
        int tren = graph[pos][i];
        if (!bio[tren]) {
            dfs2(tren);
            break;
        }
    }
}


int main() {
    memset(bio, false, sizeof bio);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int fx = 1, fy = graph[1].front();
    bio[fx] = bio[fy] = true;
    dfs1(fx);
    dfs2(fy);

    printf("%d\n", path.size());
    for (int i = 0; i < path.size(); i++)
        printf("%d ", path[i]);
    return 0;
}
