#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=acos(-1);
const ll MOD=1e9+7;
const ll INF=(1LL<<60);

int main() {
    int n;
    cin>>n;
    ll a[3*n+1];
    rep(i,3*n)cin>>a[i+1];
    ll dp1[3*n+1],dp2[3*n+1];
    priority_queue<ll,vector<ll>,greater<ll>> q1;
    ll now=0;
    for (int i=1;i<3*n+1;i++){
        if (i<=n){
            now+=a[i];
            q1.push(a[i]);
            dp1[i]=0;
            if (i==n)dp1[i]=now;
        }
        else{
            if (a[i]>q1.top()){
                now-=q1.top();
                now+=a[i];
                q1.pop();
                q1.push(a[i]);
            }
            dp1[i]=now;
        }
    }
    priority_queue<ll> q2;
    now=0;
    for (int i=3*n;i>0;i--){
        if (i>=2*n+1){
            now+=a[i];
            q2.push(a[i]);
            dp2[i]=0;
            if (i==2*n+1)dp2[i]=now;
        }
        else{
            if (a[i]<q2.top()){
                now-=q2.top();
                now+=a[i];
                q2.pop();
                q2.push(a[i]);
            }
            dp2[i]=now;
        }
    }
    ll ans=-INF;
    for (int i=n;i<2*n+1;i++){
        ans=max(ans,dp1[i]-dp2[i+1]);
    }
    cout<<ans<<endl;

    return 0;
}