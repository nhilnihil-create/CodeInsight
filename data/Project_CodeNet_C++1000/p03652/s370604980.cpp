#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;
int mod = 1000000007;

void solve();

int main(void){
    int N, M; cin >> N >> M;
    int A[N][M];
    rep(i, N){
        rep(j, M){
            int temp; cin >> temp; temp--;
            A[i][j] = temp;
        }
    }
    int idx[N] = {};
    vector<int> player[M];
    rep(i, N){
        player[A[i][0]].push_back(i);
    }

    /*
    rep(i, M){
        cout << i << ": ";
        rep(j, player[i].size()){
            cout << player[i][j] << " ";
        }
        cout << endl;
    }
    */


    //一番多いのを消して、その人たちのindexを次に進める
    int ans = 0;
    int del[M] = {};

    rep(i, M){
        if(player[i].size() > ans) ans = player[i].size();
    }
    for(int i = 0; i < M-1; i++){
        //一番多い競技はどれか
        int max_player = -1;
        int eval = 0;
        rep(j, M){
            if(player[j].size() > eval){
                eval = player[j].size();
                max_player = j;
            }
        }
        //cout << max_player << endl;
        rep(j, player[max_player].size()){
            int mv = player[max_player][j]; //動かす対象となる人
            idx[mv]++;
            while(del[A[mv][idx[mv]]] == 1) idx[mv]++;
            player[A[mv][idx[mv]]].push_back(mv);
        }

        player[max_player].clear(); //競技を消す
        del[max_player] = 1;
        //rep(j, M) cout << del[j]; cout << endl;

        //temp: 消した後の競技の中で、最大の人数の集まる競技の人数
        int temp = 0;
        rep(j, M){
            if(player[j].size() > temp) temp = player[j].size();
        }
        if(temp < ans) ans = temp;
    }
    cout << ans << endl;
    return 0;
}

void solve(){}