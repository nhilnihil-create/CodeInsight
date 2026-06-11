#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define se second
#define fi first
#define mp make_pair
#define pb push_back
#define ll long long
const int MAXN = (int)1e7 + 1000;
const int N = 105;
const int mod = (int)1e9 + 7;
const int INF = (int)1e9;
int d[N][N];
struct edge{
    int u,v,c;
};
edge e[N * N];
bool ok(int number, int v1,int v2){
    return (d[v1][e[number].u] + d[e[number].v][v2] + e[number].c == d[v1][v2]);
}
int main(){
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 0;i <= 101;i++){
        for(int j = 0;j <= 101;j++){
            d[i][j] = INF;
        }
    }
    int ans = 0;
    for(int i = 1;i <= m;i++){
        cin >> e[i].u >> e[i].v >> e[i].c;
        d[e[i].u][e[i].v] = e[i].c;
        d[e[i].v][e[i].u] = e[i].c;
    }
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    for(int i = 1;i <= m;i++){
        if(d[e[i].v][e[i].u] != e[i].c){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
