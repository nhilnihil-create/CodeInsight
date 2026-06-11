#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <bitset>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[2] = {0, 1};
ll dy[2] = {1, 0};

int main(void){
    ll n, m;
    cin >> n >> m;
    ll sum = 0;
    vector<ll> g(n+1, 0);
    bool ans = true;
    for(ll i = 0; i < m; i++){
        ll a, b;
        cin >> a >> b;
        g[a]++; g[b]++;
    }
    for(ll i = 1; i <= n; i++){
        if(g[i]%2!=0) ans=false;
    }
    if(ans==true) cout << "YES" << endl;
    if(ans==false) cout << "NO" << endl;
    return 0;
}
