#include <iostream>
#include <vector>
using namespace std;
using ll = long long int;
ll mygcd(ll m, ll n){
    if(m < n){
        ll t = n; n = m; m = t;
    }
    while(n){
        ll r = m % n;
        m = n;
        n = r;
    }
    return m;
}

int main(){
    int n;
    cin >> n;
    vector<ll> t0(n);
    for(int i = 0; i < n; i++) cin >> t0[i];
    vector<ll> t;
    t.push_back(t0[0]);
    for(int i = 1; i < n; i++){
        bool isadd = true;
        for(auto p: t){
            if(p == t0[i]) isadd = false;
        }
        if(isadd) t.push_back(t0[i]);
    }

    ll ans = t[0];
    for(int i = 1; i < t.size(); i++){
        ans = ans * (t[i]/mygcd(ans, t[i]));
    }
    cout << ans << endl;
    return 0;
}