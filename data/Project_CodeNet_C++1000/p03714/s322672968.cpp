#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define repi(i,x,n) for(ll i=x;i<(ll)(n);i++)
#define lb lower_bound
#define ub upper_bound
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000000000099;
vector<ll> dx={-1,1,0,0},dy={0,0,-1,1};
//cin.tie(0);ios::sync_with_stdio(false);



signed main(){
    ll n,ans=-INF;cin>>n;
    vector<ll> v(3*n),l(n+1,0),r(n+1,0);
    priority_queue<ll,vector<ll>, greater<ll>> ql;
    priority_queue<ll> qr;
    rep(i,3*n){
        cin>>v[i];
        if(i<n){
            ql.push(v[i]);
            l[0]+=v[i];
        }else if(2*n<=i){
            qr.push(v[i]);
            r[n]+=v[i];
        }
    }

    for(int i=n;i < 2*n;i++)
    {
        l[i-n+1]=l[i-n];
        if(ql.top()<v[i]){
            l[i-n+1]+=v[i]-ql.top();
            ql.pop();
            ql.push(v[i]);
        }
    }

    for(int i=2*n-1;n<=i;i--)
    {
        r[i-n]=r[i-n+1];
        if(qr.top()>v[i]){
            r[i-n]+=v[i]-qr.top();
            qr.pop();
            qr.push(v[i]);
        }
    }

    rep(i,n+1){
        ans=max(ans,l[i]-r[i]);
    }
    cout<<ans<<endl;
}