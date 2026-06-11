#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    rep(i,n) cin>>v[i];
    ll ans = 0;
    //前処理
    if(v[0]>x){
        ans+=v[0]-x;
        v[0]=x;
    }
    if(v[v.size()-1]>x){
        ans+=v[v.size()-1]-x;
        v[v.size()-1]=x;
    }
    vector<pair<int,int>> pii;
    rep(i,n){
        if(i==0){
            pii.push_back({0,v[0]+v[1]});
        }else if(i==n-1){
            pii.push_back({v[i]+v[i-1],0});
        }else{
            pii.push_back({v[i]+v[i-1],v[i]+v[i+1]});
        }
    }
    rep(i,n){
        if(pii[i].first>x){
            ans+=pii[i].first-x;
            pii[i+1].first-=pii[i].first-x;
            pii[i].second-=pii[i].first-=x;
        }
        if(pii[i].second>x){
            ans+=pii[i].second-x;
            pii[i+1].first-=pii[i].second-x;
            pii[i+1].second-=pii[i].second-x;
            pii[i+2].first-=pii[i].second-x;
        }
    }
    cout<<ans<<endl;
    return 0;
}