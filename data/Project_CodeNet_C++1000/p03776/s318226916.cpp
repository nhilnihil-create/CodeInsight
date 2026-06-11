#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e9;

ll c(int x,int k){
    ll res  = 1;
    for(int i=0;i<k;i++){
        res *= x-i;
        res /= i+1;
    }
    return res;
}
//input
ll n,a,b;
vector<ll>v;



int main(){
    cin >> n >> a >> b;
    v.resize(n);
    rep(i,n)cin>>v[i];
    sort(v.rbegin(),v.rend());
    if(v[0]!=v[a-1]){
        double ave = 0;
        rep(i,a){
            ave += v[i];
        }
        ave /= double(a);
        printf("%.10lf\n",ave);
        ll k=0;
        for(ll i=1;i<a;i++){
            if(v[i]==v[a-1])k++;
        }
        ll m = 0;
        for(ll i=1;i<n;i++){
            if(v[i]==v[a-1])m++;
        }
        cout << c(m,k) << endl;
    }
    else{
        double ave = v[0];
        printf("%.10lf\n",ave);
        ll m = 0;
        rep(i,n){
            if(v[i]==v[0])m++;
        }
        ll ans = 0;
        ans += pow(2,m);
        for(int i=0;i<a;i++){
            ans -= c(m,i);
        }
        for(int i=b+1;i<=m;i++){
            ans -= c(m,i);
        }
        cout << ans << endl;
    }
    return 0;
}
