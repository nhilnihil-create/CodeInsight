#include<bits/stdc++.h>
using namespace std;
using ll =long long;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(i) i.begin(),i.end()
template<typename T=ll>
using v =vector<T>;
template<typename T=ll>
using vv = vector<v<T>>;
template<typename T=ll,typename U=ll> using p = pair<T,U>;
const ll INF = (ll)1e9;
template<typename T> T chmin(T &a,T b){a=min(a,b);}
template<typename T> T chmax(T &a,T b){a=max(a,b);}

int main(){
    ll n;
    cin >> n;
    auto _max = p<>(0,0);
    rep(i,n){
        ll a,b;
        cin >> a >> b;
        if(_max.first<a){
            _max.first = a;
            _max.second = b;
        }
    }
    cout << _max.first + _max.second <<endl;    

    return 0;
}