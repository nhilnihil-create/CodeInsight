#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
*/

int main(void){
    ll N; cin >> N;
    int k=0;

    while(k*(k+1)/2 < N) k++;
    
    int dis = k*(k+1)/2 - N;

    for(int i=1; i<=k; i++){
        if(i == dis) continue;

        cout << i << endl;
    }
}