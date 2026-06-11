typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n,k;
    std::cin >> n>>k;
    vector<ll> a(n);
    vector<string> as(n);
    vector<ll> b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i]>> b[i];
        as[i] = bitset<30>(a[i]).to_string();
    }
    string ks = bitset<30>(k).to_string();
    ll res = 0;
    for (int i = 0; i < n; i++) {
        if(a[i]<=k && (a[i] | k) <=k){
            res+=b[i];
        }
    }

    for (int i = 0; i < 30; i++) {
        ll ca = 0;
        ll now = 0;
        if(ks[i]=='1'){
            
            for (int j = 0; j < 30; j++) {
                if(j<i){
                    if(ks[j]=='1')now += (ll)pow(2,29-j);
                }else if(j==i){
                    
                }else{
                    now += (ll)pow(2,29-j);
                }
            }
            
            for (int j = 0; j < n; j++) {
                if(a[j]<=now && (a[j] | now) <= now){
                    ca += b[j];
                }
            }
        }
        res = max(res,ca);
    }
    std::cout << res << std::endl;
}
