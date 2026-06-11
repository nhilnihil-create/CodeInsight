#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll INF=1e18;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n),b(n);
    rep(i,n){
        cin >> a[i];
        b[i]=a[i];
    }
    ll ans=INF;
    {
        //正、負、正、、、
        ll cst1=0,sum1=0;
        rep(i,n){
            if(i%2==0){
                if(sum1+a[i]>0){
                    sum1+=a[i];
                    continue;
                }
                cst1+=1-(sum1+a[i]);
                sum1=1;
            }
            else{
                if(sum1+a[i]<0){
                    sum1+=a[i];
                    continue;
                }
                cst1+=abs(-1-(sum1+a[i]));
                sum1=-1;
            }
        }
        ans=min(ans,cst1);
    }
    {
        //負、正、負、、、
        ll cst2=0,sum2=0;
        rep(i,n){
            if(i%2==1){
                if(sum2+a[i]>0){
                    sum2+=a[i];
                    continue;
                }
                cst2+=1-(sum2+a[i]);
                sum2=1;
            }
            else{
                if(sum2+a[i]<0){
                    sum2+=a[i];
                    continue;
                }
                cst2+=abs(-1-(sum2+a[i]));
                sum2=-1;
            }
        }
        ans=min(ans,cst2);
    }
    cout << ans << endl;
    return 0;
}
