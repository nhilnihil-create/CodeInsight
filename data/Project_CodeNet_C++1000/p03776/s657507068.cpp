#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=1<<30;
const int mod=1e9+7;
const int MOD=998244353;
vector<vector<ll>> c(55,vector<ll>(55,-1));
long long com(int a,int b){
  if(c[a][b]>=0){
    return c[a][b];
  }
  if(a==b||b==0){
    return 1;
  }
  if(a<b||a<0){
    return 0;
  }
  return c[a][b]=com(a-1,b-1)+com(a-1,b);
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,a,b;cin >> n >> a >> b;
    vector<ll> v(n);
    map<ll,int> m,p;
    for(int i=0;i<n;i++){
        cin >> v[i];
        m[v[i]]++;
    }
    sort(v.begin(),v.end(),greater<ll>());
    double ans=0;
    for(int i=0;i<a;i++){
        ans+=v[i];
        p[v[i]]++;
    }
    int u=m[v[a-1]],t=p[v[a-1]];
    cout << fixed << setprecision(10) << ans/a << endl;
    if(t==a){
        ll sum=0;
        for(ll i=a;i<=min(u,b);i++){
            sum+=com(u,i);
        }
        cout << sum << endl;
    }
    else{
        cout << com(u,t) << endl;
    }
}