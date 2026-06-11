#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
// const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
// cout << fixed << setprecision(10) << ans << endl; 有効桁数指定
// *min_element(c + l, c + r) *max_element(c + l, c + r) 配列の中のmin-max
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// ~ は、-1の時だけfalse

int main () {

    int n;cin>>n;

    ll curt,cura;

    rep(i,n) {
        ll t,a;cin>>t>>a;
        if (i==0) {
            curt=t;cura=a;
        } else {
            if (t>=curt&&a>=cura) {
                curt=t;cura=a;
                continue;
            }
            ll mult,mula;
            if (curt%t==0) mult=curt/t;
            else mult=curt/t+1;
            if (cura%a==0) mula=cura/a;
            else mula=cura/a+1;
            ll mul = max(mult,mula);
            curt=mul*t;cura=mul*a;
        }
    }

    cout<<curt+cura<<endl;


}