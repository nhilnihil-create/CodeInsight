#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define mat vector<vector<int>>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-7;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

int N, M, Q;
vector<int> G[100010];
int c[100010];
int dp[11][100010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    cin >> Q;
    for(int i = 1; i <= Q; i++){
        int v, d;
        cin >> v >> d >> c[i];
        dp[d][v] = i;
    }
    for(int i = 10; i >= 1; i--){
        for(int j = 1; j <= N; j++){
            chmax(dp[i - 1][j], dp[i][j]);
            for(auto u : G[j]){
                chmax(dp[i - 1][u], dp[i][j]);
            }
        }
    }
    for(int i = 1; i <= N; i++){
        cout << c[dp[0][i]] << endl;
    }
    return 0;
}