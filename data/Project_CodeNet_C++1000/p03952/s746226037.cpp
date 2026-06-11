#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
*/

int main(){
    int N, x; cin >> N >> x;
    if(x == 1 || x == 2*N-1){
        cout << "No" << endl;
        return 0;
    }

    if(N == 2){
        cout << "Yes" << endl;
        for(int i=1; i<=3; ++i) cout << i << endl;
        return 0;
    }

    vector<int> ans(2*N-1);
    if(x == 2){
        ans[N-2] = x+1;
        ans[N-1] = x;
        ans[N]   = x-1;
        ans[N+1] = x+2;
        int id = 1;
        for(int i=0; i<N-2; ++i){
            if(id == x-1) id = x+3;
            ans[i] = id++;
        }
        for(int i=N+2; i<2*N-1; ++i){
            if(id == x-1) id = x+3;
            ans[i] = id++;
        }
    }
    else {
        ans[N-2] = x-1;
        ans[N-1] = x;
        ans[N]   = x+1;
        ans[N+1] = x-2;
        int id = 1;
        for(int i=0; i<N-2; ++i){
            if(id == x-2) id = x+2;
            ans[i] = id++;
        }
        for(int i=N+2; i<2*N-1; ++i){
            if(id == x-2) id = x+2;
            ans[i] = id++;
        }
    }

    cout << "Yes" << endl;
    for(int i=0; i<2*N-1; ++i) cout << ans[i] << endl;
}