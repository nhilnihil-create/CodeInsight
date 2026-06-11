#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define eb emplace_back
#define pb push_back
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define ub(v,k) (upper_bound(all(v),k)-v.begin())
typedef long long ll;
typedef multiset<ll> S;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef priority_queue<ll> PQ;
typedef priority_queue<ll,vector<ll>,greater<ll>> SPQ;
using vi=vector<ll>;
using vvi=vector<vector<ll>>;
const ll inf=1001001001001001;
const int INF=1001001001;
const int mod=1000000007;
bool chmin(auto &a,auto b){if(a>b){a=b;return true;}return false;}
bool chmax(auto &a,auto b){if(a<b){a=b;return true;}return false;}

int main(){
    int n;cin>>n;
    vector<P> v(n);
    vi ans(n*n);
    rep(i,n)cin>>v[i].first;
    rep(i,n)v[i].first--;
    rep(i,n)v[i].second=i+1;
    vector<bool> used(n*n,false);
    sort(all(v));
  int l=0;
    rep(i,n){
        rep(j,v[i].second-1){
            while(used[l])l++;
            if(l>=v[i].first){
                cout<<"No"<<endl;
                return 0;
            }
            ans[l]=v[i].second;
            l++;
        }
        used[v[i].first]=true;
        ans[v[i].first]=v[i].second;
    }
    rep(i,n){
        rep(j,n-v[i].second){
            while(used[l])l++;
            if(l<v[i].first){
                cout<<"No"<<endl;
                return 0;
            }
            ans[l]=v[i].second;
            l++;
        }
    }
    cout<<"Yes"<<endl;
    rep(i,n*n){
        if(i)cout<<' ';
        cout<<ans[i];
    }
}
