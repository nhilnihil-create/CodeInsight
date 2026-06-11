#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define all(x) (x).begin(),(x).end()
template <typename T>
std::ostream& operator<<(std::ostream&s,const vector<T>&xs){
    s<<'[';for(size_t i=0;i<xs.size();++i){if(i)s<<' ';s<<xs[i];}return s<<']';
}

vll permmult(const vll& P, const vll& Q){
    ll n=P.size();
    vll PQ(n);
    for(ll i=0;i<n;++i)PQ[i]=Q[P[i]];
    return PQ;
}

vll permpow(vll P, ll k){
    ll n=P.size();
    vll result(n);
    iota(all(result),0);
    for(;k;k/=2){
        if(k%2)result=permmult(result,P);
        P=permmult(P,P);
    }
    return result;
}

vll permpow2(const vll& P, ll k) {
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

vll perminv(const vll& P) {
    ll n=P.size();
    vll Q(n);
    for(ll i=0;i<n;++i)Q[P[i]]=i;
    return Q;
}

int main() {
    ios::sync_with_stdio(false);

    if (0) {
        //vll perm{0,1, 3,2,  5,6,4,  10,7,8,9};
        vll perm{4,1,2,0,3};
        for(ll i=1;i<10;++i){
            cout<<"i="<<i<<", "<<permpow(perm,i)<<" "<<permpow2(perm,i)<<'\n';
        }
        return 0;
    }

    ll N;cin>>N;
    vll xs(N);for(ll&x:xs)cin>>x;
    ll M,K;cin>>M>>K;
    vll P(N-1);iota(all(P),0);
    for(int i=0,a;i<M&&cin>>a;++i)swap(P[a-2],P[a-1]);
    //P=permpow2(P,K);
    P=permpow(P,K);
    //P=perminv(P);
    vll ds(N-1);
    for(ll i=1;i<N;++i)ds[i-1]=xs[i]-xs[i-1];
    cout<<xs[0]<<".0\n";
    for(ll x=xs[0],i=0;i+1<N;++i){
        x+=ds[P[i]];
        cout<<x<<".0\n";
    }
}
