
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    vector<string> b(m);
    // aとbに入力
    for(int i=0; i < n; i++){
        cin >> a.at(i);
    }
    for(int i=0; i < m; i++){
        cin >> b.at(i);
    }

    rep(i,n-m+1){
        rep(j,n-m+1){
            bool x = true;
            //左から右にスライドさせ、一致しているか確認
            rep(k,m){
                // str.substr(開始位置,取り出す長さ)
                if(b.at(k) != a.at(i+k).substr(j,m)){
                    //どれか1つでも一致していない行があったらfalseに
                    x = false;
                }
            }
            if(x){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}