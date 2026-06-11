#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    ll h,w;
    cin >> h >> w;
    ll ans = h * w;
    for(ll i=0;i<2;i++){
        for(ll j=1;j<h;j++){
            ll s1,s2,s3;
            s1 = w * j;
            s2 = w * ((h-j)/2);
            s3 = w*h - s1 - s2;
            ans = min(ans,max({s1,s2,s3}) - min({s1,s2,s3}));

            s1 = w * j;
            s2 = (h-j) * (w/2);
            s3 = w*h - s1 - s2;
            ans = min(ans,max({s1,s2,s3}) - min({s1,s2,s3}));

        }
        swap(h,w);
    }
    cout << ans << endl;
    return 0;
}