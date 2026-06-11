#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG
#define fi first
#define se second

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
    ll t[n],a[n];
    rep(i,n)cin>>t[i];
    rep(i,n)cin>>a[i];
    vll h(n,-1);
    h[0]=t[0];
    rep(i,n-1){
        if (t[i+1]!=t[i]){
            h[i+1]=t[i+1];
        }
    }
    ll now=a[n-1];

    if (h[n-1]!=-1){
        if (h[n-1]!=a[n-1]){
            cout<<0<<endl;
            return 0;
        }
    }
    else {
        h[n-1]=a[n-1];
        if (a[n-1]>t[n-1]){
            cout<<0<<endl;
            return 0;
        }
    }

    for (int i=n-2;i>=0;i--){
        if (h[i]!=-1){//高さが確定している
            if (h[i]>a[i]){
                cout<<0<<endl;
                return 0;
            }
        }
        else{
            if (a[i+1]!=a[i]){
                h[i]=a[i];
                if (h[i]>t[i]){
                    cout<<0<<endl;
                    return 0;
                }
            }
        }
    }
    ll ans=1;
    vll anslist;
    rep(i,n){
        if (h[i]==-1){
            ans*=min(a[i],t[i]);
            ans%=MOD;
        }
    }
    cout<<ans<<endl;



    return 0;
}