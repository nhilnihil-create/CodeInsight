#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, N) for (int i = 0; i < (int)(N); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll MOD = 1e+9 + 7;

int main() {
    int N;
    cin >> N;
    string S1,S2;
    cin >> S1 >> S2;
    
    vector<int> S;
    bool flg = false;
    REP(i,N){
        if ( !flg ){
            if ( S1[i] == S2[i] ) {
                S.push_back(0);
            } else {
                S.push_back(1);
                flg = true;
            }
        } else {
            flg = false;
        }
    }
    
    int s = S.size();
    ll ans = -1;
    
    //for ( auto a: S ) cout << a << endl;
    
    int b = -1;
    for ( int i = 0; i < s; ++i){
        if ( b == -1 ){
            if ( S[i] == 0 ) {
                ans = 3;
                b = 0;
            } else {
                ans = 6;
                b = 1;
            }
        } else if ( b == 0 ){
            if ( S[i] == 0 ){
                ans = ( ans * 2 ) % MOD;
                b = 0;
            } else {
                ans = ( ans * 2 ) % MOD;
                b = 1;
            }
        } else {
            if ( S[i] == 0 ){
                ans = ans;
                b = 0;
            } else {
                ans = ( ans * 3 ) % MOD;
                b = 1;
            }
        }
    }
    
    ans %= MOD;
    if ( ans < 0 ) ans += MOD;
    cout << ans << endl;
    
    
    return 0;
}
