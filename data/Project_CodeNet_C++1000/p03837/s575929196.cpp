#include<bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (n); i++)
 
int main(){
    int N,M;
    cin >> N >> M;
    int G[N][N] = {};
    vector<vector<int>> E;
    rep(i,N){
        rep(j,N){
            if(i==j) G[i][j] = 0;
            else G[i][j] = 10000000;
        }
    }
    rep(i,M){
        int a,b,c;
        cin >> a >> b >> c;
        a--,b--;
        G[a][b] = c;
        G[b][a] = c;
        vector<int> e = {a,b,c};
        E.emplace_back(e);
    }

    rep(k,N){
        rep(i,N){
            rep(j,N){
                G[i][j] = min(G[i][j],G[i][k] + G[k][j]);
            }
        }
    }

    int res = 0;
    rep(i,E.size()){
        int a = E[i][0];
        int b = E[i][1];
        int c = E[i][2];
        rep(i,N){
            if(G[i][a] + c == G[i][b]){
                res++;
                break;
            }
        }
    }
    cout << M - res << endl;

    return 0;
}