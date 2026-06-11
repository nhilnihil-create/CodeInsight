#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
    int n;
    cin>>n;
    priority_queue<ll> ba;
    priority_queue<ll,vector<ll>,greater<ll>> fr;
    ll sumf=0,sumb=0;
    vector<ll> v;
    rep(i,3*n){
        ll t;cin>>t;
        if(i<n){sumf+=t;fr.push(t);}
        else if(i>=2*n){sumb+=t;ba.push(t);}
        else{v.push_back(t);}
    }
    vector<ll> ansf,ansb;
    ansf.push_back(sumf);ansb.push_back(sumb);
    rep(i,n){
        //topと比べて操作する必要がない
        sumf+=v[i];
        fr.push(v[i]);
        sumf-=fr.top();
        fr.pop();
        ansf.push_back(sumf);
    }
    for(int i=n-1;i>=0;i--){
        sumb+=v[i];
        ba.push(v[i]);
        sumb-=ba.top();
        ba.pop();
        ansb.push_back(sumb);
    }
    ll ans=-LINF;
    for(int i=0;i<=n;i++){
        ans=max(ans,ansf[i]-ansb[n-i]);
    }
    cout<<ans<<endl;
    return 0;
}