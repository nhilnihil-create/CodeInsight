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
    ll N, a,b,c,d; cin >> N >> a >> b >> c >> d;

    for(int k=0; k<N; k++){
        ll left = a+c*k-d*(N-1-k);
        ll right = a+d*k-c*(N-1-k);

        if(left <= b && b <= right){
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
}