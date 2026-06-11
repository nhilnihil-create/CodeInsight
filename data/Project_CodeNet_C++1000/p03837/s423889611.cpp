#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const int mod = 1000000007;


int main(){
    int N, M;
    cin >> N >> M;
    vector<int> a(M), b(M), c(M);
    rep(i, M){
        cin >> a[i] >> b[i] >> c[i];
        --a[i]; --b[i];
    }
    vector<vector<int>> v(N, vector<int>(N,INF)); // 隣接行列
    rep(i, N){
        v[i][i] = 0;
    }
    rep(i, M){
        v[a[i]][b[i]] = c[i];
        v[b[i]][a[i]] = c[i];
    }

    // ワーシャルフロイド
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
            }
        }
    }
    int res = 0;
    for(int i = 0; i < M; i++){
        if(c[i] > v[a[i]][b[i]]){
            res++;
        }
    }
    cout << res << endl;
    return 0;
}
