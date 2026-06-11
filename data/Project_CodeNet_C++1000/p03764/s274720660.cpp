#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <cstring>
#include <unordered_set>
#include <unordered_map>

using namespace std;
 
typedef long long ll;
typedef pair<int, int> P;
static const int INF = 1000010000;
static const ll MOD = 1000000007;
 
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb push_back
#define mp make_pair
#define np next_permutation
#define pq priority_queue

//int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};

ll f(ll a, ll b){
    return a * b % MOD;
}

int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> x, y;
    REP(i, n){
        ll tmp;
        cin >> tmp;
        x.pb(tmp);
    }
    ll a = n - 1, b = 1;
    ll sx = 0;
    REP(i, n - 1){
        sx = (sx + f(f(a, b), (x[i + 1] - x[i]))) % MOD;
        a--; b++;
    }
    ll ans = 0;
    REP(i, m){
        ll tmp;
        cin >> tmp;
        y.pb(tmp);
    }
    a = m - 1; b = 1;
    REP(i, m - 1){
        ans = (ans + f(f(f(a, b), (y[i + 1] - y[i])), sx)) % MOD;
        a--; b++;
    }
    cout << ans << endl;
}

// 1 1 1 1 2 3 4
// 0 -1 -2 -3 -4 -4 -4