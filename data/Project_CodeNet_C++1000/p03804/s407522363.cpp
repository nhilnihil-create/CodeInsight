#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int M,N; cin >> N >> M;
    vector<vector<char>> A(N),B(M);
    rep(i,N){
        rep(j,N){
            char x; cin >> x;
            A[i].push_back(x);
        }
    }
    rep(i,M){
        rep(j,M){
           char x; cin>>x;
           B[i].push_back(x);
        }
    }

    bool ans=false;
    for(int i=0; i<=N-M; i++){
        for(int j=0; j<=N-M; j++){
            bool flg=true;
            // 一致チェックループ
            for(int k=0; k<M; k++){
                for(int l=0; l<M; l++){
                    if(A[i+k][j+l] != B[k][l]){
                        flg = false;
                    }

                }
            }
            if(flg) ans=true;
        }
    }

    // rep(i,N){
    //     rep(j,N){
    //         cerr << A[i][j];
    //     }
    //     cerr << endl;
    // }
    // cerr << "-------------" << endl;
    // rep(i,M){
    //     rep(j,M){
    //        cerr << B[i][j];
    //     }
    //     cerr << endl;
    // }


    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
