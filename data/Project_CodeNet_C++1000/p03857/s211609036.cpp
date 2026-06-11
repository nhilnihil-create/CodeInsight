#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;
ll uni[400000];
ll root(ll u){
    if(uni[u]<0)return u;
    return uni[u]=root(uni[u]);
}

void connect(int a,int b){
    a=root(a);
    b=root(b);
    if(a==b)return;
    if(a>b){
        a^=b;
        b^=a;
        a^=b;
    }
    uni[a]+=uni[b];
    uni[b]=a;
    return;
}
ll size(ll u){
    return -uni[root(u)];
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    memset(uni,-1,sizeof(uni));
    ll n,k,l;
    cin>>n>>k>>l;
    ll p,q,r,s;
    
    for(int i=0;i<k;i++){
        cin>>p>>q;
        p--;q--;
        connect(p,q);
    }
    for(int i=0;i<l;i++){
        cin>>r>>s;
        r--;s--;
        connect(r+200000,s+200000);
    }
    vector<pair<ll,ll> > v(n),v1(n);

    for(int i=0;i<n;i++){
        v1[i]=v[i]=make_pair(root(i),root(i+200000)-200000);
    }
    sort(be(v));
    for(int i=0;i<n;i++){
        cout << (upper_bound(be(v),v1[i])-lower_bound(be(v),v1[i]))<<" ";
    }
    cout << endl;
    return 0;
}