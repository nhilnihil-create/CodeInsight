
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 1'010'000'000'000'000'017LL
#define mod 1000000007LL
#define eps 0.0001
#define ALL(x) (x).begin(), (x).end()
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define SZ(x) ((ll)(x).size())
#define sum(x) accumulate(ALL(x), 0LL)//?
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll N, A, B, C;
vector<ll> h;
bool D(ll x){
        ll ans = x;
        rep(i, N){
            ll r = h.at(i)-B*x;
            if (r > 0) ans-=r/C + (r%C != 0);
        }
        if(ans>=0) return true;
        else return false;
    }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> A >> B;
    C = A-B;
    h.resize(N);
    rep(i, N){
        cin >> h.at(i);
    }
    ll ok = 1000000001, ng = 0;
    ll mid;
    while (ok-ng>1){
        mid = (ok+ng)/2;
        if(D(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}