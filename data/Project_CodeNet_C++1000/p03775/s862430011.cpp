#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD=1000000007;
#define REP(i,n) for(ll i=0; i<(n); i++)
#define REP2(i,x,n) for(ll i=x; i<(n); i++)
const long long INF = numeric_limits<long long>::max();
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main()
{
    ll N;
    cin >>N;

    ll digit = INF;
    for ( ll i = 1; i * i <= N; ++ i ){
        if ( (N%i) == 0 ){
            ll d1 = 0;
            for ( ll v = i; v > 0; v /= 10 )    d1++;
            ll d2  = 0;
            for ( ll v = N/i; v > 0; v /= 10 )    d2++;
            chmin(digit, max(d1,d2));
        }
    }
    #ifdef SOURCE_TEST
        for ( auto& p : pairs ){
            cout << p.first << ":" << p.second << endl;
        }
    #endif

    cout << digit << endl;
    return 0;
}