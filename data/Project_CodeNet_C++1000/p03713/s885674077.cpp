#include <bits/stdc++.h>
using  namespace std;
typedef long long ll;
int main(){
    ll h, w, pase1, pase2, pase3, max_pase, min_pase;
    ll ans = pow(10, 10);
    cin >> h >> w;
    for(ll i=1;i<h;i++){
        pase1 = i*w;
        if(w%2==0){
            pase2 = (h-i)*(w/2);
            ans = min(ans, abs(pase1-pase2));
        }else{
            pase2 = (h-i)*(w/2);
            pase3 = (h-i)*(w/2+1);
            max_pase = max(pase1, pase2);
            max_pase = max(max_pase, pase3);
            min_pase = min(pase1, pase2);
            min_pase = min(min_pase, pase3);
            ans = min(ans, (max_pase-min_pase));
        }
    }
    for(ll i=1;i<w;i++){
        pase1 = i*h;
        if(h%2==0){
            pase2 = (w-i)*(h/2);
            ans = min(ans, abs(pase1-pase2));
        }else{
            pase2 = (w-i)*(h/2);
            pase3 = (w-i)*(h/2+1);
            max_pase = max(pase1, pase2);
            max_pase = max(max_pase, pase3);
            min_pase = min(pase1, pase2);
            min_pase = min(min_pase, pase3);
            ans = min(ans, (max_pase-min_pase));
        }
    }
    if(h%3==0){
        cout << 0 << endl;
        return 0;
    }else {
        ans = min(w, ans);
    }
    if(w%3==0){
        cout << 0 << endl;
        return 0;
    }else {
        ans = min(h, ans);
    }

    cout << ans << endl;
    return 0;
 
}
