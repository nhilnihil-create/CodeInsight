#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
ll INF = 1e15;
 
ll max3(ll a, ll b, ll c){
    return max(max(a, b), c);
}

ll min3(ll a, ll b, ll c){
    return min(min(a, b), c);
}
int main(void){
    ll h, w;
    cin>>h>>w;
    ll ans = INF;
    /*一番左に敷き詰める方*/
    for(ll j = 1;j<=w-1;j++){
        /*縦に分ける方*/
        ll spl = (w-j)/2;
        ll now1 = max3(h*j, h*(spl), h*(w-j-spl))-min3(h*j, h*(spl), h*(w-j-spl));
        ans = min(ans, now1);
        /*横に分ける方*/
        ll spl2 = h/2;
        ll now2 = max3(h*j, (w-j)*spl2, (w-j)*(h-spl2))-min3(h*j, (w-j)*spl2, (w-j)*(h-spl2));
        ans = min(ans, now2);
    }
    /*一番上に敷き詰める方*/
    for(ll i = 1;i<=h-1;i++){
        /*縦に分ける方*/
        ll spl = (h-i)/2;
        ll now1 = max3(w*i, w*(spl), w*(h-i-spl))-min3(w*i, w*(spl), w*(h-i-spl));
        ans = min(ans, now1);
        /*横に分ける方*/
        ll spl2 = w/2;
        ll now2 = max3(w*i, (h-i)*spl2, (h-i)*(w-spl2))-min3(w*i, (h-i)*spl2, (h-i)*(w-spl2));
        ans = min(ans, now2);
    }
    cout<<ans<<endl;
    return 0;
}