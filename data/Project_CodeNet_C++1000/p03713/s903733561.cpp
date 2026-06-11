#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll=long long;
using vi = vector<int>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;

ll solve(ll h,ll w){
    ll res=LINF;
    ll men = h*w;
    for(ll i=0;i<=h;i++){
        ll S1 = w*i;
        ll S2 = (h-i)/2LL * w;
        ll S3 = men - S1 - S2;
        if(min({S1,S2,S3})<0) continue;
        ll tmp = max({S1,S2,S3}) - min({S1,S2,S3});
        res = min(res,tmp);
    }
    for(ll i=0;i<=h;i++){
        ll S1 = w*i;
        ll S2 = (h-i) * (w/2);
        ll S3 = men - S1 - S2;
        if(min({S1,S2,S3})<0) continue;
        ll tmp = max({S1,S2,S3}) - min({S1,S2,S3});
        res = min(res,tmp);
    }
    return res;
}

int main(){
    ll h,w;
    cin >> h >> w;
    cout << min(solve(h,w),solve(w,h)) << endl;
}