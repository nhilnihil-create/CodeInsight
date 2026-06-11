#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
  
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
*/

int main(){
    int N; cin >> N;
    vector<string> s(2);
    cin >> s[0] >> s[1];

    const ll mod = 1000000007;
    ll ans = 1;
    int id = 0;
    bool flg;
    if(s[0][0] == s[1][0]){
        id = 1;
        ans = 3;
        flg = true;
    } else {
        id = 2;
        ans = 6;
        flg = false;
    }

    while(id<N){
        if(flg == true && s[0][id] == s[1][id]){
            ans = ans*2%mod;
            id++;
        } else if(flg == true && s[0][id] != s[1][id]){
            ans = ans*2%mod;
            id += 2;
            flg = false;
        } else if(flg == false && s[0][id] == s[1][id]){
            id++;
            flg = true;
        } else if(flg == false && s[0][id] != s[1][id]){
            ans = ans*3%mod;
            id += 2;
        }
    }

    cout << ans << endl;
}