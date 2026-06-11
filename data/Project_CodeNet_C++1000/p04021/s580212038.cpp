#include <bits/stdc++.h>
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define rep(i,n) FOR(i,0,n)
using namespace std;
typedef long long ll;

ll n,a,ans;
pair<ll,ll> p[100009];

int main(){
    cin>>n;
    rep(i,n){
        cin>>a;
        p[i]={a,i};
    }
    sort(p,p+n);
    rep(i,n){
        if(abs(p[i].second-i)%2==1)ans++;
    }
    cout<<ans/2<<endl;
}