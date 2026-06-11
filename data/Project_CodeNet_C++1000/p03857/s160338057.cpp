#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

const int MAX_N = 2e5 + 5;
int N, K, L;
vector<int> G[2][MAX_N];
int used[2][MAX_N];

void bfs(int s, int cnt, int num){
    queue<int> q;
    used[num][s] = cnt; q.push(s);

    while(q.size()){
        int u = q.front(); q.pop();
        for(auto v : G[num][u]){
            if(!used[num][v]){
                used[num][v] = cnt;
                q.push(v);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N >> K >> L;
    for(int i=0;i<K;i++){
        int p, q; cin >> p >> q;
        G[0][p].push_back(q); G[0][q].push_back(p);
    }
    for(int i=0;i<L;i++){
        int p, q; cin >> p >> q;
        G[1][p].push_back(q); G[1][q].push_back(p);
    }

    int cnt = 1;
    for(int i=1;i<=N;i++) if(!used[0][i]) bfs(i, cnt++, 0);
    cnt = 1;
    for(int i=1;i<=N;i++) if(!used[1][i]) bfs(i, cnt++, 1);

    map<P, int> c;
    for(int i=1;i<=N;i++) c[P(used[0][i], used[1][i])]++;

    for(int i=1;i<=N;i++) cout << c[P(used[0][i], used[1][i])] << ' ';
    cout << endl;
    return 0;
}