typedef long long ll;
typedef long double ld;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n,m;
    std::cin >> n>>m;
    
    vector<vector<ll>> edges(n);
    
    for (int i = 0; i < m; i++) {
        ll a,b;
        std::cin >> a>>b;
        a--;b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    vector<bool> used(n,false);
    
    ll s = 0;
    ll t = edges[0][0];
    ll it=t;
    used[s] = used[t] = true;
    vector<ll> sv,tv;
    while(true){
        bool ok = true;
        for (auto e : edges[s]) {
            if(!used[e]){
                used[e]=true;
                s = e;
                sv.push_back(e);
                ok = false;
                break;
            }
        }
        if(ok)break;
    }
    while(true){
        bool ok = true;
        for (auto e : edges[t]) {
            if(!used[e]){
                used[e]=true;
                t = e;
                tv.push_back(e);
                ok = false;
                break;
            }
        }
        if(ok)break;
    }
    std::cout << sv.size()+tv.size()+2 << std::endl;
    for (int i = 0; i < sv.size(); i++) {
        std::cout << sv[sv.size()-1-i]+1<<" ";
    }
    std::cout <<1<<" "<<it+1<<" ";
    for (int i = 0; i < tv.size(); i++) {
        std::cout << tv[i]+1<<" ";
    }
    std::cout << std::endl;
}
