#include<bits/stdc++.h>
using namespace std;
#define all(vec) vec.begin(),vec.end()
typedef long long int ll;
typedef pair<ll,ll> P;
const ll MOD=10000;
const double INF=1000000000;
const int MAX=100001;
int main(){
    ll w,h;
    cin>>w>>h;
    vector<P> v;
    for(int i=0;i<w;i++){
        ll p;cin>>p;
        v.push_back(P(p,0));
    }
    for(int i=0;i<h;i++){
        ll q;cin>>q;
        v.push_back(P(q,1));
    }
    sort(all(v));
    ll ans=0;
    ll a=w+1;ll b=h+1;
    for(auto& e:v){
        if(e.second){
            b--;
            ans+=e.first*a;
        }else{
            a--;
            ans+=e.first*b;
        }
    }
    cout<<ans<<endl;
    return 0;
}

                           
