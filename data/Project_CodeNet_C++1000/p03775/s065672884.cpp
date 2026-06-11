#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
vector<ll> divisor(ll n){
    vector<ll> res;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            res.push_back(i);
            if(i!=n/i) res.push_back(n/i);
        }
    }
    return res;
}
ll n;
ll m;
ll ans=100000000000000;
int main(void){
    cin>>n;
    vector<ll> a;
    a=divisor(n);
    for(int i=0;i<a.size();i++){
        ll t=max(a[i],n/a[i]);
        m=0;
        while(t>0){
            t=t/10;
            m++;
        }
        ans=min(m,ans);
    }
    cout<<ans<<endl;

}

