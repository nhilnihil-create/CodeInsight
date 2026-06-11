#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define all(a) (a).begin(),(a).end()
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=10000000000000000;

int bit[200003],nn=200003;
int sum(int i){
    int s=0;
    while (i>0){
        s+=bit[i];
        i -= i & -i;
    }
    return s;
}
void add(int i,int x){
    while (i<=nn){
        bit[i]+=x;
        i+= i& -i;
    }
}

int main() {
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n+1);
    a.at(0)=0;
    rep(i,n){
        ll f;
        cin >> f;
        a.at(i+1)=a.at(i)+f-k;
    }
    vector<ll> b=a;
    sort(all(b));
    map<ll,int> m;
    rep(i,n+1){
        m[b.at(i)]=i+1;
    }
    rep(i,n+1){
        a.at(i)=m[a.at(i)];
    }
    ll ans=0;
    ll u=0;
    rep(i,n+1){
        ans+=sum(a.at(i));
        add(a.at(i),1);
    }   
    cout << ans << endl;
}