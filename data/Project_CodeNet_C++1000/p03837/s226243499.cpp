#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<iomanip>
#include<map>
#include<cstring>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define vi vector<int>
#define vivi vector<vi>
const int INF = int(1e9);
typedef long long int ll;

/* -- template -- */

int main(){
    int N, M;cin >> N >> M;
    int G[N][N];
    rep(i, N)
        rep(j, N)
            if(i == j)
                G[i][j] = 0;
            else
                G[i][j] = INF;
    int a[M], b[M], c[M];
    rep(i, M){
        cin >> a[i] >> b[i] >> c[i];
        --a[i];--b[i];
        G[a[i]][b[i]] = G[b[i]][a[i]] = c[i];
    }
    for(int k = 0;k < N;++k){
        for(int i = 0;i < N;++i){
            for(int j = 0;j < N;++j){
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
    int ans = 0;
    for(int i = 0;i < M; ++i){
        bool flg = false;
        for(int j = 0; j < N; ++j){
            if(G[j][a[i]] + c[i] == G[j][b[i]])flg = true;
        }
        if(!flg)ans++;
    }
    cout << ans;
    //cout << G[0][3] << endl;
}
