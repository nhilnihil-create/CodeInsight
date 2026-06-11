#include <bits/stdc++.h>
# define ll int64_t
#define rep(i,n) for(ll i=0;i<n;i++)
#define rrep(i,n) for(ll i=1;i<=n;i++)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define mod 1000000007

using namespace std;

bool compare_by_b(pair<string,ll> a,pair<string,ll> b){
    if(a.second != b.second) return a.second<b.second;
    else return a.first<b.first;
}

bool my_compare(pair<string,ll> a,pair<string,ll> b){
    
    if(a.first != b.first) return a.first<b.first;
    if(a.second != b.second) return a.second>b.second;
    else return true;
}

int main(){
    ll n,t;
    cin>>n>>t;
    vector<ll> a(n);
    rep(i,n) {
        cin>>a[i];
    }
    ll sum=t;
    rep(i,n-1){
        if(a[i+1]-a[i]>=t) sum+=t;
        else sum+=a[i+1]-a[i];
    }
    cout<<sum<<endl;
    return 0;
}