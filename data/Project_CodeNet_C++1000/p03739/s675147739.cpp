#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define prt(v) cout<<(v)<<"\n";
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl "\n"
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;


signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> A(n,0);
    for(ll i=0;i<n;++i)cin>>A[i];

    vl a=A;

    ll &N=n;

    //正からはじまる
    ll sum=0;
    ll ans1=0;
    for(ll i=0;i<N;++i){
        if(i%2==0){
            if(sum+a[i]>0)sum+=a[i];
            else {
                ans1+=llabs(1-sum-a[i]);
                a[i]=1-sum;
                sum+=a[i];
            }
        }
        else {
            if(sum+a[i]<0)sum+=a[i];
            else {
                ans1+=llabs(-1-sum-a[i]);
                a[i]=-1-sum;
                sum+=a[i];
            }
        }
    }

    a=A;

    sum=0;
    ll ans2=0;
    for(ll i=0;i<N;++i){
        if(i%2==1){
            if(sum+a[i]>0)sum+=a[i];
            else {
                ans2+=llabs(1-sum-a[i]);
                a[i]=1-sum;
                sum+=a[i];
            }
        }
        else {
            if(sum+a[i]<0)sum+=a[i];
            else {
                ans2+=llabs(-1-sum-a[i]);
                a[i]=-1-sum;
                sum+=a[i];
            }
        }
    }

    prt(min(ans1,ans2))

    return 0;
}
