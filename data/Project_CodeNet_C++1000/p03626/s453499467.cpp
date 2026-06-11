#include <bits/stdc++.h>

#define REP( i, n )     for( int (i) = 0; (i) < (n); (i)++ )
#define ALL( a )        (a).begin(), (a).end()

using namespace std;
using ll = long long;
using P = pair<int, int>;

template<class T>bool chmax( T& a, const T& b ) { if( a < b ) { a = b; return 1; } return 0; }
template<class T>bool chmin( T& a, const T& b ) { if( a > b ) { a = b; return 1; } return 0; }

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

int main(){
    int N; cin >> N;
    string s1, s2; cin >> s1 >> s2;

    ll ans = 0;
    bool flag = false;
    REP( i, N ){
        if( s1[i] == s2[i] ){
            if( i == 0 ) ans += 3;
            else{
                if( !flag ){
                    ans *= 2;
                    ans %= MOD;
                }
                flag = false;
            }
        }else{
            if( i == 0 ) ans += 6;
            else{
                if( flag ){
                    ans *= 3;
                    ans %= MOD;
                }else{
                    ans *= 2;
                    ans %= MOD;
                }
            }
            flag = true;
            i++;
        }
    }

    cout << ans << endl;
}
