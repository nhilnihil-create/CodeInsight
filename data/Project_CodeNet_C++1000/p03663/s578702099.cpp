#include <bits/stdc++.h>
using namespace std;
#define ll long long

char query(ll x) {
    char res;
    printf("? %lld\n", x);
    cin >> res;
    return res; 
}

int main(){
    ll l = 1, r = 10;
    for (int i = 0; i < 9; i++) {
        char d = query(r);
        if (d == 'N') {
            break;
        }
        if (r == 1e9) {
            ll t = 1;
            for (int j = 0; j < 10; j++) {
                if (query(t*2) == 'Y') {
                    printf("! %lld\n", t);
                    break;
                }
                t *= 10;
            }
            return 0;
        }
        r *= 10;
        l *= 10;
    }
    l--;
    
    ll m = r/10;
    while (r-l>1) {
        ll c = (l+r)/2;
        if (query(c*100) == 'N') l = c;
        else r = c;
    }
    if (10*m > r) printf("! %lld\n", r);
    else printf("! %lld\n", m);
    return 0;
}
