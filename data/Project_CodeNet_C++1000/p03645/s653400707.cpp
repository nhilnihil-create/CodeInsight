#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,m;
    cin >> n >> m;
    vector<ll> a(m);
    vector<ll> b(m);
    for (ll i = 0;i < m;i++){
        cin >> a[i] >> b[i];
    }
    bitset<200000> s;
    bitset<200000> g;

    for (ll i = 0; i < m; i++){
        if (a[i] == 1){
            s.set(b[i], 1);
        }
        if (b[i] == n){
            g.set(a[i], 1);
        }
    }
    
    if ((s&g) != 0){
        cout << "POSSIBLE" << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
}