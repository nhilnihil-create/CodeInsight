#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
*/

int main(){
    int N; cin >> N;
    string s; cin >> s;
    bool flg = false;

    for(int bit=0; bit<4; bit++){
        string ans = s;
        // first, fix pre 2 characters
        for(int i=0; i<2; i++){
            if(bit&1<<i) ans[i] = 'S';
            else ans[i] = 'W';
        }

        // build ans
        for(int i=2; i<N; i++){
            if((ans[i-1] == 'S' && s[i-1] == 'o') || (ans[i-1] == 'W' && s[i-1] == 'x'))  ans[i] = ans[i-2];
            else if((ans[i-1] == 'S' && s[i-1] == 'x') || (ans[i-1] == 'W' && s[i-1] == 'o')) ans[i] = (ans[i-2] == 'S')? 'W':'S';
        }

        // check phase
        bool ok = true;
        for(int i=0; i<N; i++){
            if(s[i] == 'o'){
                if(ans[i] == 'S'){
                    if(ans[(i-1+N)%N] != ans[(i+1)%N]) ok = false;
                } else {
                    if(ans[(i-1+N)%N] == ans[(i+1)%N]) ok = false;
                }
            } else {
                if(ans[i] == 'S'){
                    if(ans[(i-1+N)%N] == ans[(i+1)%N]) ok = false;
                } else {
                    if(ans[(i-1+N)%N] != ans[(i+1)%N]) ok = false;
                }
            }
        }
        if(ok){
            cout << ans << endl;
            return 0;
        }
    }

    cout << "-1" << endl;
    return 0;

}