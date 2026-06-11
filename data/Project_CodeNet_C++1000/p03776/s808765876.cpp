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

const ll mod=1e9+7;

ll ch[55][55];

ll choose(ll n,ll k){
    if(k>n) return 0;
    if(ch[n][k]!=0) return ch[n][k];
    if(n>5 && k>=1) return ch[n][k]=choose(n-1,k)+choose(n-1,k-1);
    if(2*k>n) k=n-k;
    ll res=1;
    rep(i,k){
        res*=n-i;
    }
    rep(i,k){
        res/=(i+1);
    }
    return ch[n][k]=res;
}

int main()
{
    ll n,a,b;
    cin >> n >> a >> b;
    vector<double> v(n);
    rep(i,n){
        cin >> v[i];
    }
    sort(v.rbegin(),v.rend());
    double ave=0;
    rep(i,a){
        ave+=v[i];
    }
    ll cnt_sum=0;
    rep(i,a){
        if(v[i]>v[a-1]) cnt_sum++;
    }
    
    ll cnt_val=0;
    rep(i,n){
        if(v[i]==v[a-1]) cnt_val++;
    }
    if(cnt_sum==0){
        cout << setprecision(30);
        cout << v[0] << endl;
        ll ans=0;
        for(ll i=a;i<=b;i++){
            ans+=choose(cnt_val,i);
            //cout <<cnt_val << " " << i << " " <<  choose(cnt_val,i) << endl;
        }
        cout << ans << endl;
        return 0;
    }
    //cout << cnt_sum << " " << cnt_val << endl;
    cout << setprecision(30);
    ave/=a;
    cout << ave << endl;
    ll ans=0;
    
    ans=choose(cnt_val,a-cnt_sum);
    cout << ans << endl;
    
    return 0;
} 