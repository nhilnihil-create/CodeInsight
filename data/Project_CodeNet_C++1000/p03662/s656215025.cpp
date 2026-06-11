#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;
const static ll MOD = 1e9+7;


int main(){
    int N; cin >> N;
    vector<vector<int>> V(N);
    for(int i = 0; i < N-1; i++){
        int a, b; cin >> a >> b; a--;b--;
        V[a].push_back(b);
        V[b].push_back(a);
    } 

    bool grid[N];
    memset(grid, false, sizeof(grid));
    grid[0] = true;

    queue<pair<int,int>> Q;
    Q.push(make_pair(0, 0));
    vector<int> dB(N), dW(N);

    while(!Q.empty()){
        int v = Q.front().first;
        int cnt = Q.front().second;
        Q.pop();
        //cout << v << endl;
        for(auto u : V[v]){
            //cout << " " << u << endl;
            if(!grid[u]){
                grid[u] = true;
                Q.push(make_pair(u, cnt+1));
                dB[u] = cnt+1;
            }
        }
    }

    memset(grid, false, sizeof(grid));
    grid[N-1] = true;
    Q.push(make_pair(N-1, 0));


    while(!Q.empty()){
        int v = Q.front().first;
        int cnt = Q.front().second;
        Q.pop();
        //cout << v << endl;
        for(auto u : V[v]){
            //cout << " " << u << endl;
            if(!grid[u]){
                grid[u] = true;
                Q.push(make_pair(u, cnt+1));
                dW[u] = cnt+1;
            }
        }
    }
    int b = 0, w = 0;
    for(int i = 0; i < N; i++) {
        if(dB[i] <= dW[i]) b++;
        else w++;
    }

    if(b > w) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;

}