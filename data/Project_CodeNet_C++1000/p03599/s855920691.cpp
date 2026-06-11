#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep2(i,s,n) for(int i = (s); i < (n); ++i)
#define ll long long
#define ld long double
#define P pair<ll,ll>
#define all(v) v.begin(),v.end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

ll sumofketa(ll a,ll b){
    string s=to_string(a),t=to_string(b);
    return max(s.size(),t.size());
}

int main(void)
{
    ll a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    ll ans1=100*a,ans2=0;
    double tmp=0;
    rep(i,31)rep(j,31){
        rep(k,101)rep(l,101){
            double w = 100 * (a*i + b*j), s = c*k + d*l;
            if(w==0) continue;
            if(w + s > f) break;
            if(s > e * (a*i + b*j)) break;
            if(s / (w + s) > tmp){
                tmp = s / (w + s);
                ans1 = w + s;
                ans2 = s;
            }
        }
    }
    cout << ans1 << " " << ans2 <<endl;
    return 0;
}