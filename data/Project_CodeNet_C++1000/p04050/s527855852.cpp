#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> v[2];
    rep(i, M){
        int A;
        cin >> A;
        v[A%2].pb(A);
    }
    vector<int> a, b;
    if(N%2 == 0){
        if(sz(v[1]) == 0){
            if(M == 1){
                a.pb(N), b.pb(N-1), b.pb(1);
            }
            else{
                for(auto &e: v[0]) a.pb(e), b.pb(e);
                b.front()++, b.back()--;
            }
        }
        elif(sz(v[1]) == 2){
            a.pb(v[1][0]), b.pb(v[1][0]+1);
            for(auto &e: v[0]) a.pb(e), b.pb(e);
            a.pb(v[1][1]);
            if(v[1][1] > 1) b.pb(v[1][1]-1);
        }
        else{
            cout << "Impossible" << endl;
            return 0;
        }
    }
    else{
        if(sz(v[1]) == 1){
            if(M == 1){
                if(N == 1) a.pb(1), b.pb(1);
                else a.pb(N), b.pb(N-1), b.pb(1);
            }
            else{
                a.pb(v[1][0]), b.pb(v[1][0]+1);
                for(auto &e: v[0]) a.pb(e), b.pb(e);
                b.back()--;
            }
        }
        else{
            cout << "Impossible" << endl;
            return 0;
        }
    }
    for(auto &e: a) cout << e << ' '; cout << endl;
    cout << sz(b) << endl;
    for(auto &e: b) cout << e << ' '; cout << endl;
}