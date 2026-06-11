#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<x<<endl
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll LINF = LLONG_MAX;
const int INF = INT_MAX;
const double PI=acos(-1);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    ll n; cin>>n;
    vector<ll> a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    ll res=0;
    ll sum=0;
    rep(i,0,n){
        sum+=a[i];
        if(i%2==0){
            if(sum<=0){
                // ng
                res+=abs(sum-1);
                sum=1;
            }
        }else{
            if(sum>=0){
                // ng
                res+=abs(sum+1);
                sum=-1;
            }
        }
        // debug(res);
        // debug(sum);
    }
    ll ans=res;
    // cout<<endl;
    res=0;
    sum=0;
    rep(i,0,n){
        sum+=a[i];
        if(i%2==1){
            if(sum<=0){
                // ng
                res+=abs(sum-1);
                sum=1;
            }
        }else{
            if(sum>=0){
                // ng
                res+=abs(sum+1);
                sum=-1;
            }
        }
        // debug(res);
        // debug(sum);
    }
    cout<<min(res,ans)<<endl;
}