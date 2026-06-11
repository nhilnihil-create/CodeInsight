#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,cnt,a,bit[(1LL<<20)],ans;
vector<ll>v,v2,v1;
ll sum(ll i){
    ll s=0;
    while(i>0){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(ll i,ll x){
    while(i<=n+1){
        bit[i]+=x;
        i+=i&-i;
    }
    return ;
}
int main(void){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        v.push_back(cnt);
        v2.push_back(cnt);
        cin>>a;
        cnt+=a;
        cnt-=k;
    }
    v.push_back(cnt);
    v2.push_back(cnt);
    sort(v2.begin(),v2.end());
    for(int i=0;i<=n;i++){
        ll L=lower_bound(v2.begin(),v2.end(),v[i])-v2.begin();
        v1.push_back(L+1);
    }
    for(ll x:v1){
        ans+=sum(x);
        add(x,1);
    }
    cout<<ans<<endl;
}
