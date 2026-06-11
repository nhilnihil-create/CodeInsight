#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair <int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
const char nl = '\n';

void solve() {
    int w, h, n;
    cin >> w >> h >> n;
    vector<vector<int>> vec(h, vector<int>(w));
    for(int i = 0; i < n; ++i){
        int x, y, a;
        cin >> x >> y >> a;
        if(a == 1){
            for(int i = 0; i < h; ++i){
                for(int j = 0; j < x; ++j){
                    vec.at(i).at(j) = 1;
                }
            }
        }
        if(a == 2){
            for(int i = 0; i < h; ++i){
                for(int j = x; j < w; ++j){
                    vec.at(i).at(j) = 1;
                }
            }
        }
        if(a == 3){
            for(int i = 0; i < y; ++i){
                for(int j = 0; j < w; ++j){
                    vec.at(i).at(j) = 1;
                }
            }
        }
        if(a == 4){
            for(int i = y; i < h; ++i){
                for(int j = 0; j < w; ++j){
                    vec.at(i).at(j) = 1;
                }
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            if(vec.at(i).at(j) == 0){
                sum += 1;
            }
        }
    }
    cout << sum << nl;
}
int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
