#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,W;

int main(){
    cin >> n >> W;
    vector<ll> a[4];
    ll memo;
    for(ll i=0;i<n;i++){
        ll w,v;
        cin >> w >> v;
        if(i==0) memo=w;
        if(w-memo==0) a[0].push_back(v);
        if(w-memo==1) a[1].push_back(v);
        if(w-memo==2) a[2].push_back(v);
        if(w-memo==3) a[3].push_back(v);
    }
    for(ll i=0;i<4;i++){
        sort(a[i].begin(),a[i].end());
        a[i].push_back(0);
        reverse(a[i].begin(),a[i].end());
        for(ll j=0;j<a[i].size()-1;j++){
            a[i][j+1]=a[i][j]+a[i][j+1];
        }
    }
    ll res=0;
    for(ll i=0;i<a[0].size();i++){
        for(ll j=0;j<a[1].size();j++){
            for(ll k=0;k<a[2].size();k++){
                for(ll l=0;l<a[3].size();l++){
                    if((memo*(i+j+k+l)+j+2*k+3*l)<=W){
                        res=max(res,a[0][i]+a[1][j]+a[2][k]+a[3][l]);
                    }
                }
            }
        }
    }
    cout << res << endl;
}
