#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const ll MOD=1e9+7;
int main(){
    int n,m;
    cin>>n>>m;
    vector<ll> x(n),y(m);
    for(int i=0;i<n;i++) cin>>x[i];
    for(int i=0;i<m;i++) cin>>y[i];

    auto calc=[](vector<ll> v){
        int n=v.size();
        ll res=0;
        for(int i=0;i+1<n;i++){
            res+=ll(i+1)*(n-1-i)%MOD*(v[i+1]-v[i])%MOD;
        }
        return res%MOD;
    };
    cout<<(calc(x)*calc(y))%MOD<<endl;
    return 0;
}