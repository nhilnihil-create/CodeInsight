#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

vector<int> pathes[100050];
int dist[100050][2];

void bfs(int from, int cost, int checker){
    for(int i = 0; i < pathes[from].size(); i++){
        int to = pathes[from][i];
        if(dist[to][checker] <= cost + 1) continue;
        dist[to][checker] = cost + 1;
        bfs(to, cost + 1, checker);
    }
}

int main() {
    //cout.precision(10);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        pathes[a].push_back(b);
        pathes[b].push_back(a);
    }
        for(int i = 1; i <= n; i++){
            dist[i][0] = INF;
            dist[i][1] = INF;
        }
        dist[1][0] = 0;
        dist[n][1] = 0;
        bfs(1, 0, 0);
        bfs(n, 0, 1);
        int counter[2];
        counter[0] = 0;
        counter[1] = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i][0] <= dist[i][1]) counter[0]++;
            else counter[1]++;
        }
    if(counter[1] >= counter[0]){
        cout << "Snuke" << endl;
    } else {
        cout << "Fennec" << endl;
    }
    return 0;
}
