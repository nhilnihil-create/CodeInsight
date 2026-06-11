#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
using ll = unsigned long long;

int main(){
    int n;
    cin>>n;
    set<ll> s;
    for(int i=0;i<n;i++){
        ll t;
        cin>>t;
        s.insert(t);
    }

    ll ans=1;
    for(ll t : s){
        ans=ans/__gcd(ans,t)*t;
    }
    cout<<ans<<endl;
}