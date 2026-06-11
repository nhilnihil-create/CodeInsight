#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=998244353;
const ll mod=1e9+7;
signed main(){
    ll n;cin>>n;
    vector<pll>x(n);
    rep(i,n){
        ll a;cin>>a;
        a--;
        x[i]=mp(a,i+1);
    }
    sort(all(x));
    vector<ll>a(n*n);
    ll j=0;
    ll now=0;
    vector<ll>used(n+1);
    bool f=1;
    rep(i,n*n){
        if(x[now].first==i){
            if(used[x[now].second]<x[now].second-1)f=0;
            used[x[now].second]++;
            a[i]=x[now].second;
            now++;
            continue;
        }else{
            while(j<n&&used[x[j].second]>=x[j].second-1){
                j++;
            }
            if(j==n)continue;
            used[x[j].second]++;
            a[i]=x[j].second;
        }
    }
    now=0;
    j=0;
    rep(i,n*n){
        if(a[i])continue;
        while(used[x[j].second]==n){
            j++;
        }
        a[i]=x[j].second;
        used[a[i]]++;
    }
    rep(i,n+1)used[i]=0;
    rep(i,n*n){
        used[a[i]]++;
        if(x[now].first==i){
            if(used[a[i]]!=a[i])f=0;
            now++;
        }
    }
    if(!f){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    rep(i,n*n){
        cout<<a[i]<<' ';
    }
    cout<<endl;
}