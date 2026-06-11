typedef  long long ll;
#include <bits/stdc++.h>
using namespace std;
ll n;
vector<vector<ll>> edges;

ll dfs(ll x){
    multiset<ll> tmp;
    if(!edges[x].size()){
        return 0;
    }
    for (auto e : edges[x]) {
        tmp.insert(dfs(e));
    }
    ll ans = 0;
    ll ind = edges[x].size()-1;
    for (auto e : tmp) {
        ans = max(ans,e+ind);
        ind--;
    }

    return 1+ans;
}

int main() {
    std::cin >> n;
    edges.resize(n);
    
    for (int i = 0; i < n-1; i++) {
        ll a;
        std::cin >> a;
        edges[a-1].push_back(i+1);
    }
    std::cout << dfs(0) << std::endl;
}
