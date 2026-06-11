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

const ll mod = 1000000007;

int main(){
    int N; cin >> N;
    string s[2];
    cin >> s[0] >> s[1];

    ll ans;
    int pos;
    char preType;


    if(s[0][0] == s[1][0]){
        pos = 1;
        ans = 3;
        preType = 'a';
    } else{
        pos = 2;
        ans = 6;
        preType = 'b';
    }

    while(pos < N){
        if(preType == 'a'){
            if(s[0][pos] == s[1][pos]){
                ans = ans*2%mod;
                pos++;
            } else {
                ans = ans*2%mod;
                pos += 2;
                preType = 'b';
            }
        } else {
            if(s[0][pos] == s[1][pos]){
                pos++;
                preType = 'a';
            } else {
                pos += 2;
                ans = ans*3%mod;
            }
        }
    }

    cout << ans << endl;
}