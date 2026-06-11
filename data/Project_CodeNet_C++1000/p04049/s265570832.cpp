#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define PB push_back
#define PII pair <long long , long long>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int MAXN = 2e5 + 10 , INF = 1e9;
vector <int> edges[MAXN];
int n , k;
int cnt;
int dis[MAXN];
int ans[MAXN];

void dfs(int v , int par , int root) {
    for (auto u : edges[v]) {
        if(u != par) {
            dis[u] = dis[v] + 1;
            if(dis[u] > (k / 2)) {
                ans[root]++;
            }
            dfs(u , v , root);
        }
    }
}

void dfs2(int v , int par) {
    for (auto u : edges[v]) {
        if(u != par) {
            if(dis[u] == -1) {
                dis[u] = dis[v] + 1;
                if(dis[u] > (k / 2)) {
                    cnt++;
                }
            }
            dfs2(u , v);
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int x , y;
        cin >> x >> y;
        x--; y--;
        edges[x].PB(y);
        edges[y].PB(x);
    }   
    if(!(k % 2)) {
        int mini = INF;
        for (int i = 0; i < n; ++i) {
            dis[i] = 0;
            dfs(i , -1 , i);
        }
        for (int i = 0; i < n; ++i) {
            mini = min(mini , ans[i]);
        }
        cout << mini << endl;
    }
    else {
        int mini = INF;
        for (int i = 0; i < n; ++i) {
            for (int j : edges[i]) {
                cnt = 0;
                fill(dis , dis + n , -1);
                dis[i] = 0; dis[j] = 0;
                dfs2(i , -1);
                mini = min(mini , cnt);
            }
        }
        cout << mini << endl;
    }
}
