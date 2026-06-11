/*
これを入れて実行
g++ code.cpp
./a.out
 */
 
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <math.h>
#include <tuple>
#include <iomanip>
#include <bitset>
#include <functional>
#include <cassert>

#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
int dy4[4] = {-1, 0, +1, 0};
int dx4[4] = {0, +1, 0, -1};
int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
const long long INF = 1LL << 60;
const ll MOD = 1e9 + 7;
 
bool greaterSecond(const pair<int, int>& f, const pair<int, int>& s){
    return f.second > s.second;
}
 
ll gcd(ll a, ll b){
	if (b == 0)return a;
	return gcd(b, a % b);
}
 
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

ll conbinationMemo[100][100];

void cmemoInit(){
    rep(i, 100){
        rep(j, 100){
            conbinationMemo[i][j] = -1;
        }
    }
}
 
ll nCr(ll n, ll r){
    if(conbinationMemo[n][r] != -1) return conbinationMemo[n][r];
    if(r == 0 || r == n){
        return 1;
    } else if(r == 1){
        return n;
    }
    return conbinationMemo[n][r] = (nCr(n - 1, r) + nCr(n - 1, r - 1));
}
 
ll nPr(ll n, ll r){
    r = n - r;
    ll ret = 1;
    for (ll i = n; i >= r + 1; i--) ret *= i;
    return ret;
}
//-----------------------ここから-----------
int main(void){
    ll n, m;
    cin >> n >> m;
    ll dist[110][110];
    rep(i, 110) rep(j, 110) dist[i][j] = INF;
    rep(i, 110) dist[i][i] = 0;
    vector<pair<pair<ll,ll>,ll>> e;
    rep(i, m){
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
        e.push_back({{a, b}, c});
    }
    rep(via, n){
        rep(i, n){
            rep(j, n){
                dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
            }
        }
    }
    ll ans = 0;
    rep(i, m){
        bool use = false;
        rep(j, n){
            rep(k, n){
                if(dist[j][e[i].first.first] + e[i].second + dist[e[i].first.second][k] == dist[j][k]){
                    use = true;
                }
                
            }
        }
        if(use) ans++;
    }
    cout << m - ans << endl;
}
