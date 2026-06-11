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
    int N; cin >> N;
    vector<int> p(N+1, 0);
    vector<int> a(N+1), b(N+1);

    for(int i=1; i<=N; ++i) cin >> p[i];
    for(int i=1; i<=N; ++i){
        a[i] = 50000 * i;
        b[i] = 50000 * (N+1-i);
    }

    for(int i=1; i<=N; ++i){
        a[p[i]] -= (50000 - i);
    }

    for(int i=1; i<=N; ++i){
        if(i>1) cout << " ";
        cout << a[i];
    }
    cout << endl;
    for(int i=1; i<=N; ++i){
        if(i>1) cout << " ";
        cout << b[i];
    }
    cout << endl;

}