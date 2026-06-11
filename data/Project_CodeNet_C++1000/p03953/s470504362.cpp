#include <bits/stdc++.h>
#define rep(i, a, b) for(ll i = ll(a); i < ll(b); i++)
#define rer(i, a, b) for(ll i = ll(a) - 1; i >= ll(b); i--)
#define sz(v) (int)(v).size()
#define pb push_back
#define sc second
#define fr first
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
using namespace std;
typedef long long int ll;
typedef pair <int, int> P;

const ll MOD=1000000007;
ll N;
double x[100000], d[100000];
ll M,K;
ll a[100000];
vector<int> mul(vector<int> X, vector<int> Y){
    vector<int> Z(N-1,0);
    rep(i,0,N-1){
        Z[i]=X[Y[i]];
    }
    return Z;
}
vector<int> pow(vector<int> X, ll n){
    vector<int> Z(N-1,0);
    if(n==0){
        rep(i,0,N-1) Z[i]=i;
        return Z;
    }
    Z=pow(X,n/2);
    Z=mul(Z,Z);
    if(n%2) Z=mul(X,Z);
    return Z;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    rep(i,0,N)cin>>x[i];
    rep(i,0,N-1) d[i]=x[i+1]-x[i];
    cin>>M>>K;
    rep(i,0,M) cin>>a[i];
    vector<int> v(N-1,0);
    rep(i,0,N-1) v[i]=i;
    rep(i,0,M){
        swap(v[a[i]-2], v[a[i]-1]);
    }
    vector<int> p(N-1,0);
    rep(i,0,N-1){
        p[v[i]]=i;
    }
    p=pow(p,K);
    vector<double> ans(N-1,0);
    rep(i,0,N-1){
        ans[p[i]]=d[i];
    }
    ll res=x[0];
    rep(i,0,N){
        if(i==0) cout <<setprecision(15)<<x[0]<<"\n";
        else {
            res+=ans[i-1];
            cout <<setprecision(15)<<res<<"\n";
        }
    }
}