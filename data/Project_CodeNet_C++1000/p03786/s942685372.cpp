#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef long long ll;
typedef pair<ll,ll> pint;


int main(){
    ll n;cin>>n;
    priority_queue<ll,vector<ll>,greater<ll> > a;
    ll a1;
    ll ans=n;
    rep(i,n){
        cin>>a1;
        a.push(a1);
    }
    while(1<a.size()){
        ll b = a.top();a.pop();
        ll b1 = a.top();a.pop();
        if(2*b<b1){
            a.push(b+b1);
            ans=a.size();
        }
        else{
            a.push(b+b1);
        }
    }
    cout<<ans<<endl;
}