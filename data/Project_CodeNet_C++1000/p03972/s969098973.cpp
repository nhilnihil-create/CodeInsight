typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll w,h;
    std::cin >> w>>h;
    
    vector<ll> pw(w);
    vector<ll> ph(h);
    for (int i = 0; i < w; i++) {
        std::cin >> pw[i];
    }
    for (int i = 0; i < h; i++) {
        std::cin >> ph[i];
    }
    
    sort(pw.begin(),pw.end());
    sort(ph.begin(),ph.end());
    
    ll cntw,cnth;
    cntw = cnth = 0;
    
    ll ans = 0;
    
    while(cntw<w&&cnth<h){
        if(pw[cntw]<=ph[cnth]){
            ans += pw[cntw]*(h-cnth+1);
            cntw++;
        }else{
            ans += ph[cnth]*(w-cntw+1);
            cnth++;
        }
    }
    if(cntw==w){
        for (int i = cnth; i < h; i++) {
            ans += ph[i];
        }
    }else{
        for (int i = cntw; i < w; i++) {
            ans += pw[i];        
        }
    }
    
    std::cout << ans << std::endl;
    
}

