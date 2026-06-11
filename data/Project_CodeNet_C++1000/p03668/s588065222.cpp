#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int Grundy[100050];
int N;
vector<int> pathes[100500];
int parent[100050];

void bfs(int from) {
    Grundy[from] = 0;
    for(int i = 0; i < pathes[from].size(); i++) {
        int to = pathes[from][i];
        if(to == parent[from]) continue;
        parent[to] = from;
        bfs(to);
        Grundy[from] ^= (Grundy[to] + 1);
    }
    return;
}

int main() {
    //cout.precision(10);
    cin >> N;
    for(int i = 1; i < N; i++) {
        int x, y;
        cin >> x >> y;
        pathes[x].push_back(y);
        pathes[y].push_back(x);
    }
    parent[1] = -1;
    bfs(1);
    if(Grundy[1] == 0) cout << "Bob" << endl;
    else cout << "Alice" << endl;
    return 0;
}
