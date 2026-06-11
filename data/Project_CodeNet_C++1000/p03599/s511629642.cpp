#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(long long i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int main(){
    vector<ll> var(6);
    rep(i,6) cin>>var[i];
    pair<double,double> res={100*min(var[0],var[1]), 0};
    for(ll x=0; 100*x*var[0]<=var[5]; x++){
        for(ll y=0; 100*(x*var[0]+y*var[1])<=var[5]; y++){
            if(x==0 && y==0) continue;
            ll water=100*(var[0]*x+var[1]*y);
            if(water>var[5]) continue;
            ll tmp = min(var[5]-water, var[4]*(var[0]*x+var[1]*y));

            for(ll i=0; var[2]*i<=tmp; i++){
                for(ll j=0; var[2]*i+var[3]*j<=tmp; j++){
                    double sugar=var[2]*i+var[3]*j;
                    if(sugar>tmp) continue;
                    if( (res.first==0 && res.second==0) || res.second/res.first < sugar/(water+sugar)){
                        res.first=water+sugar;
                        res.second=sugar;
                    }
                }
            }
            
        }
    }
    cout<<res.first<<' '<<res.second<<endl;
    return 0;
}