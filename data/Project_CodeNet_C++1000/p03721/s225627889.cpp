#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main() {
    long long N,K; cin >> N >> K;
    long long ans;
    map<ll, ll> m{};
    for(ll i=0;i<N;i++){
        ll a,b; cin >> a >> b;
        m[a]+=b;
    }
    for(auto i:m){
        K-=i.second;
        if(K<=0) {ans=i.first; break;}
    }
    cout << ans << endl;
}

