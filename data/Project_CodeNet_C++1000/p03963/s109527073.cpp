#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ll RepeatSquaring(ll N, ll P){
    if(P==0) return 1;
    if(P%2==0){
        ll t = RepeatSquaring(N, P/2);
        return t*t;
    }
    return N * RepeatSquaring(N, P-1);
}

int main() {
    ll N, K;
    cin >> N >> K;
    printf("%lld\n", K  * RepeatSquaring(K-1,N-1));

}