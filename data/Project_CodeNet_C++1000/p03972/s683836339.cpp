#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

int main(){
    int W, H;
    cin >> W >> H; 

    vector<ll> P;
    vector<ll> Q;
    REP(i,W){
        ll p;
        cin >> p;
        P.push_back(p);
    }
    REP(i,H){
        ll q;
        cin >> q;
        Q.push_back(q);
    }

    sort(P.begin(), P.end());
    sort(Q.begin(), Q.end());

    int pi = 0;
    int qi = 0;
    ll ans = 0;
    while(pi < W || qi < H){
        ll p = 1e9;
        ll q = 1e9;
        if(pi < W) p = P[pi];
        if(qi < H) q = Q[qi];

        if(p >= q){
            ans += q * (1 + W - pi);
            qi++;
        }
        else{
            ans += p * (1 + H - qi);
            pi++;
        }
    }

    cout << ans << endl;
    return 0;
}
