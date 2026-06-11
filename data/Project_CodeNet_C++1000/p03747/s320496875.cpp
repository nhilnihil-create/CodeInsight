#include <bits/stdc++.h>
#define ll long long
#define V vector<long long>
#define VV vector<vector<long long>>
#define rep(i,n) for(ll (i)=0;(i)<(n);++(i))
using namespace std;

int main(){
    ll n,l,t;
    cin>>n>>l>>t;
    V x(n),w(n);
    rep(i,n)cin>>x[i]>>w[i];
    ll num=0;
    for(int i=1;i<n;i++){
        if(w[0]!=w[i]){
            if(w[0]==1){
                ll d=(x[i]-x[0]+l)%l;
                if(2*t>=d){
                    num++;
                    num+=(2*t-d)/l;
                }
            }else{
                ll d=(x[0]-x[i]+l)%l;
                if(2*t>=d){
                    num++;
                    num+=(2*t-d)/l;
                }
            }
        }
    }
    ll label;
    if(w[0]==1){
        label=(num+n)%n;
    }else{
        label=(-num%n+n)%n;
    }
    vector<ll> f(n);
    ll first;
    rep(i,n){
        ll dist;
        if(w[i]==1){
            dist=((x[i]+t)%l+l)%l;
        }else{
            dist=((x[i]-t)%l+l)%l;
        }
        f[i]=dist;
    }
    first=f[0];
    sort(f.begin(),f.end());
    ll st=lower_bound(f.begin(), f.end(),first)-f.begin();
    if(upper_bound(f.begin(), f.end(), first)-lower_bound(f.begin(), f.end(),first)==2){
        if(w[0]==1){
            label--;
        }else{
            label++;
            st++;
        }
    }
    rep(i,n){
        cout<<f[(st-label+i+n)%n]<<endl;
    }
}
