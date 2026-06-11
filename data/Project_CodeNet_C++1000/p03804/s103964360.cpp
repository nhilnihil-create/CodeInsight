#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N, M;
    cin >> N >> M;
    vector<string> a(N);
    vector<string> b(M);
    rep(i, N) cin >> a[i];
    rep(i, M) cin >> b[i];

    bool ans = false;

    //開始点(左上）を決定するforループ
    rep(i, N-M+1){
        rep(j, N-M+1){
            int cnt = 0;
            //各行を見るforループ
            rep(k, M){
                string S = a[i+k].substr(j, M);
                string T = b[k];
                if(S == T) cnt++;
            }
            if(cnt == M) ans = true;
        }
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" <<endl;
    return 0;
}