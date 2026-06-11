#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll comp(ll n,ll r){
    if(r>n||r<0) return 0;
    ll i;
    ll c=1;
    for(ll i=1;i<=r;i++){
        c=c*(n+1-i)/i;
    }
    return c;
}

int main(){
    ll N,A,B; cin >> N >> A >> B;
    ll v[N+1];
    map<ll,ll> ma;
    for(ll i=1;i<=N;i++){
        cin >> v[i];
        ma[v[i]]++;
    }
    sort(v+1,v+N+1,greater<ll>());
    double ave=0;
    for(int i=1;i<=A;i++){
        ave+=v[i];
        //cout << v[i] << endl;
    }
    ave/=A;
    cout << setprecision(20) << ave << endl;
    ll ans=0;
    if(v[1]!=v[A]){
        ll cnt=0;
        for(ll i=1;i<=A;i++){
            if(v[i]==v[A]) cnt++;
        }
        ans=comp(ma[v[A]],cnt);
    }else{
        for(ll i=A;i<=B;i++){
            if(v[i]==v[A]){
                ans+=comp(ma[v[A]],i);
            }
        }
    }
    cout << ans << endl;
}