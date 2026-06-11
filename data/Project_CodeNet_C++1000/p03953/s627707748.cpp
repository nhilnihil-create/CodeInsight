#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define all(x) (x).begin(),(x).end()
template <typename T>
std::ostream& operator<<(std::ostream&s,const vector<T>&xs){
    s<<'[';for(size_t i=0;i<xs.size();++i){if(i)s<<' ';s<<xs[i];}return s<<']';
}

vll permpow(const vll& P, ll k) {
    ll n=P.size();
    vll Q(n);
    vll done(n);
    vll cycle;
    for(ll i=0;i<n;++i)if(!done[i]){
        done[i]=true;
        cycle.clear();
        cycle.push_back(i);
        for(ll j=P[i];j!=i;j=P[j]){
            cycle.push_back(j);
            done[j]=true;
        }
        ll m=cycle.size();
        for(ll j=0;j<m;++j)Q[P[cycle[j]]] = cycle[(j+k+1)%m];
    }
    return Q;
}

int main() {
    ios::sync_with_stdio(false);

    ll N;cin>>N;
    vll xs(N);for(ll&x:xs)cin>>x;
    ll M,K;cin>>M>>K;
    vll P(N-1);iota(all(P),0);
    for(int i=0,a;i<M&&cin>>a;++i)swap(P[a-2],P[a-1]);
    P=permpow(P,K);
    vll ds(N-1);
    for(ll i=1;i<N;++i)ds[i-1]=xs[i]-xs[i-1];
    cout<<xs[0]<<".0\n";
    for(ll x=xs[0],i=0;i+1<N;++i){
        x+=ds[P[i]];
        cout<<x<<".0\n";
    }
}
