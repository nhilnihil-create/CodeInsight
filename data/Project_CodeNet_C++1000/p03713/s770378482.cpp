#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll h,w, Min = 1e18;

int main(){
    scanf("%lld%lld",&h,&w);
    if(h % 3 == 0 || w % 3 == 0) printf("0\n");
    else{
        for(ll i = 1; i < w; i++){
            ll One = i * h;
            ll w1 = w - i;
            ll Two = h / 2 * w1;
            ll San = (h - h / 2) * w1;
            Min = min(Min, max(One, max(Two, San)) - min(One, min(Two,San)) );
        }
        Min = min(Min, w);
        
        for(ll i = 1; i < h; i++){
            ll One = i * w;
            ll h1 = h - i;
            ll Two = w / 2 * h1;
            ll San = (w - w / 2) * h1;
            Min = min(Min, max(One, max(Two, San)) - min(One, min(Two,San)) );
        }
        Min = min(Min,h);
        printf("%lld\n",Min);
    }
    return 0;
}
