#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll n, k, l, p, q, r, s, road[200100], train[200100];
const ll INF = 1000000000000000;
map<P, ll> mp;
vector<ll> roa[200100], tra[200100];

void dfsr(ll x, ll y){
    road[x] = y;
    for (ll i = 0; i < roa[x].size(); i++){
        if (road[roa[x][i]] == INF) dfsr(roa[x][i], y);
    }
}

void dfst(ll x, ll y){
    train[x] = y;
    for (ll i = 0; i < tra[x].size(); i++){
        if (train[tra[x][i]] == INF) dfst(tra[x][i], y);
    }
}

int main(void){
    // Your code here!
    cin >> n >> k >> l;
    for (ll i = 1; i <= n; i++) road[i] = INF, train[i] = INF;
    for (ll i = 0; i < k; i++){
        cin >> p >> q;
        roa[p].push_back(q);
        roa[q].push_back(p);
    }
    for (ll i = 0; i < l; i++){
        cin >> r >> s;
        tra[r].push_back(s);
        tra[s].push_back(r);
    }
    for (ll i = 1; i <= n; i++){
        if (road[i] == INF) dfsr(i, i);
        if (train[i] == INF) dfst(i, i);
    }
    for (ll i = 1; i <= n; i++){
        mp[P(road[i], train[i])]++;
    }
    for (ll i = 1; i <= n; i++){
        cout << mp[P(road[i], train[i])] << ' ';
    }
}
