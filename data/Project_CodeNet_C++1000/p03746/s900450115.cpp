#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define fi first
#define se second

typedef long long ll;

using namespace std;

int n, m;

bool u[100500];

vector<int> g[100500];

deque<int> q;

void bfs() {

u[1] = 1;
q.pb(1);

for(int i = 1; i <= n; i++) {
    int v = q.front();
    for(int j = 0; j < g[v].size(); j++) {
        int to = g[v][j];
        if(!u[to]) {
            q.push_front(to);
            u[to] = 1;
            break;
        }
    }
    v = q.back();
    for(int j = 0; j < g[v].size(); j++) {
        int to = g[v][j];
        if(!u[to]) {
            q.pb(to);
            u[to] = 1;
            break;
        }
    }
}
cout << q.size() << '\n';
while(!q.empty()) {
    cout << q.back() << ' ';
    q.pop_back();
}
}


int main(){

cin >> n >> m;
for(int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].pb(b);
    g[b].pb(a);
}
bfs();

return 0;
}
